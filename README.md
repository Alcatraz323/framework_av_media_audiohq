# project_audiohq_prebuilt
编译aosp或其各种变体(lineage, exthm)时的食用方法


1.将本项目clone到framework/av/media(或许能在manifest执行)


2.将framework/av/media/libaudioprocessing/Android.bp中

    cc_library_shared {
        name: "libaudioprocessing",
        defaults: ["libaudioprocessing_defaults"],

        srcs: [
            "BufferProviders.cpp",
            "RecordBufferConverter.cpp",
        ],
        whole_static_libs: ["libaudioprocessing_arm"],
    }

### 改为

    cc_library_shared {
        name: "libaudioprocessing_deprecated",
        defaults: ["libaudioprocessing_defaults"],

        srcs: [
        "BufferProviders.cpp",
        "RecordBufferConverter.cpp",
        ],
        whole_static_libs: ["libaudioprocessing_arm"],
    }


3.在device/\[manufacture\]/\[devicename\]/\[devicename\].mk中(就是那个一堆PRODUCT\_COPY\_FILES的)添加

    PRODUCT_PACKAGES += \
        libaudioheadquarter \
        audiohq \
        audiohqserver


4.对于有vendor分区的设备，可以将audiohq.te放到device/\[manufacture\]/\[devicename\]/sepolicy里并将file_context，service_context的内容追加到同名文件
没有的如(cancro),可放在system/sepolicy/vendor,并追加该文件夹下的file_context,service_context


5.正常编译

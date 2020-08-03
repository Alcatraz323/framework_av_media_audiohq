#include <stdlib.h>
#include <stdio.h>
#include <string>

namespace android
{

struct aahq_cblk
{
    bool isCrtSuccessful;
    int pid;
    int session;
    float v_left;
    float v_right;
    float v_final;
    bool muted;
    bool isActive;
};

std::string getStatus();

std::vector<aahq_cblk *> getCblks();

std::string getVersion();

std::string getSwitches();

std::string listProfiles();

std::string listMuted();

int setControlMode(int mode);

int setDefaultSilent(bool enabled);

int setWeakKeyAdjust(bool enabled);

int setProfile(std::string process, float left, float right, float finalv, bool control_lr, bool isweakkey);

int unsetProfile(std::string process, bool isweakkey);

int mute(std::string process, bool isweakkey);

int unmute(std::string process, bool isweakkey);

int clear();

std::string listBuffers(int mode);

std::string getDefaultProfile();

int setDefaultProfile(float left, float right, float finalv, bool control_lr);

std::string getProfile(std::string process, bool isweakkey);

std::string getOvrStatus();

} // namespace android

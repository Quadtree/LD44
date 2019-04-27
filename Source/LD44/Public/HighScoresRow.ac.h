
#ifdef fun
    #undef fun
#endif

#define mods(...)
#define im(...)
#define blueprintEvent(...)
#define prop(...)
#define extends(...)
#define classMods(...)
#define fun         UHighScoresRow
TMap<EUpgradeType, int32> UHighScoresRow::GetUpgradeLevels(){ return UpgradeLevels; }
void UHighScoresRow::SetUpgradeLevels(TMap<EUpgradeType, int32> value){ UpgradeLevels = value; }
float UHighScoresRow::GetTime(){ return Time; }
void UHighScoresRow::SetTime(float value){ Time = value; }
bool UHighScoresRow::GetIsMe(){ return IsMe; }
void UHighScoresRow::SetIsMe(bool value){ IsMe = value; }

#include "Public/UpgradeType.h"

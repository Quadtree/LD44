#include "HighScoresRow.h"
#include "HighScoresRow.ac.h"

extends(UObject)

prop(TMap<EUpgradeType, int32> UpgradeLevels)
prop(float Time)
prop(bool IsMe)
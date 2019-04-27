#pragma once

#include "EngineMinimal.h"
#include "Public/UpgradeType.h"
#include "HighScoresRow.generated.h"

UCLASS()
class LD44_API UHighScoresRow : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetUpgradeLevels, BlueprintSetter=SetUpgradeLevels)
	TMap<EUpgradeType, int32> UpgradeLevels;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetTime, BlueprintSetter=SetTime)
	float Time;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetIsMe, BlueprintSetter=SetIsMe)
	bool IsMe;

public:
	UFUNCTION(BlueprintGetter, BlueprintPure)
	TMap<EUpgradeType, int32> GetUpgradeLevels();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetUpgradeLevels(TMap<EUpgradeType, int32> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetTime();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetTime(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	bool GetIsMe();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetIsMe(bool value);

};

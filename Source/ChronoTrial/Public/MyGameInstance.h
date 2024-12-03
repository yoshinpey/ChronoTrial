#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 保存してある値を読み書きするクラス
 */

UCLASS()
class CHRONOTRIAL_API UMyGameInstance : public UGameInstance
{
    GENERATED_BODY()
	
    UPROPERTY()
    bool CPlusData = true;

public:
    virtual void Init() override;
    virtual void Shutdown() override;
    void ReadConfigValues();
    void WriteConfigValues();

    // プレイヤー設定
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    int32 PlayerHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float MaxWalkSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float Acceleration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float Gravity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float JumpForce;

    // 敵設定
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float EnemyMoveSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float EnemyAttackRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float EnemyAttackPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float EnemyHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float RangedAttackSpeed;

    // 武器設定
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun")
    float GunFireRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun")
    float GunDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun")
    int32 GunMagazine;

    // 設定
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float PADSensitivity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float MouseSensitivity;

    //Reverse
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reverse")
    int32 ReverseTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reverse")
    int32 ReverseCoolDownTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reverse")
    float ReverseSpeed;

};

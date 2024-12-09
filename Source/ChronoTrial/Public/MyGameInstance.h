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
    bool CPlusData = true;      // C++データが有効かどうかのフラグ

public:
    virtual void Init() override;       // 初期化
    virtual void Shutdown() override;   // 終了
    void ReadConfigValues();            // 設定値を読み込む
    void WriteConfigValues();           // 設定値を書き込む

    /*----- 全般的な設定 -----*/

    // マウスの感度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float MouseSensitivity;

    // パッドの感度X
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float PadSensitivityX;

    // パッドの感度Y
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float PadSensitivityY;

    // エイム中の減速率
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float AimSencePercent;

    /*----- プレイヤーの設定 -----*/

    // 体力
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    int32 PlayerHP; 

    // 移動速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float PlayerMaxWalkSpeed;

    // 加速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float PlayerAcceleration;

    // 重力
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float PlayerGravity;

    // 地面との抵抗
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float PlayerFriction;

    // ジャンプ力
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float PlayerJumpForce;

    // 空中でどれくらい操作できるか
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float PlayerAirControl;

    // 空中での抵抗
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    float PlayerAirFriction;


    /*----- 敵の設定 -----*/

    // 敵の移動速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float EnemyMoveSpeed; 

    // 敵の攻撃頻度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float EnemyAttackRate; 

    // 敵の攻撃力
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float EnemyAttackPower; 

    // 敵の体力
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float EnemyHP; 

    // 遠距離攻撃の速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float EnemyRangedAttackSpeed;


    /*----- 武器の設定 -----*/

    // 武器の射撃速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun")
    float GunFireRate; 

    // 武器のダメージ
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun")
    float GunDamage; 

    // 武器のマガジン容量
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun")
    int32 GunMagazine; 


    /*----- 時間逆転機能の設定 -----*/

    // 逆転可能な時間の長さ
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reverse")
    int32 ReverseTime; 

    // クールダウン時間
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reverse")
    int32 ReverseCoolDownTime;

    // 逆転時の速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reverse")
    float ReverseSpeed;

};

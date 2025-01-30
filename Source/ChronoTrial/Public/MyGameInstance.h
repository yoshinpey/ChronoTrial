#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"


/**
 * 敵のパラメータを表す構造体
 */
USTRUCT(BlueprintType)
struct FEnemyParameters
{
    GENERATED_BODY()

    // 移動速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float MoveSpeed;

    // 攻撃力
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float AttackPower;

    // 体力
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float HP;

    // 遠距離攻撃の飛翔速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float RangedAttackSpeed;

    //// 攻撃頻度 ビヘイビアツリーだからめんどい！！！
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    //float AttackRate;
    //// 遠距離攻撃の開始距離
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    //float RangedAttackDist;

    // コンストラクタ（デフォルト値の設定）
    FEnemyParameters()
        : MoveSpeed(0.0f), AttackPower(0.0f), HP(0.0f), RangedAttackSpeed(0.0f)
    {
    }
};

/**
 * 保存してある値を読み書きするクラス
 */
UCLASS()
class CHRONOTRIAL_API UMyGameInstance : public UGameInstance
{
    GENERATED_BODY()

    UPROPERTY()
    bool CPlusData = true;      // C++データが有効かどうかのフラグ

    FString ConfigFilePath; // 設定ファイルのパス

public:
    virtual void Init() override;       // 初期化
    virtual void Shutdown() override;   // 終了
    void ReadConfigValues();            // 設定値を読み込む
    void WriteConfigValues();           // 設定値を書き込む

    /*----- レベル間で使用する変数 -----*/

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DirecStageSelect = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsTrialMode = false;

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

    // タイマーの制限時間
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    int32 TimerCount;

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

    // 通常の敵のパラメータ
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    FEnemyParameters NormalEnemy;

    // 遠距離攻撃の敵のパラメータ
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    FEnemyParameters RangedEnemy;

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


    /*----- スキル設定 -----*/

    // 逆転可能な時間の長さ
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reverse")
    int32 ReverseTime;

    // クールダウン時間
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reverse")
    int32 ReverseCoolDownTime;

    // 逆転時の速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reverse")
    float ReverseSpeed;

    // 加速スキル
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Accel")
    int32 AccelTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Accel")
    int32 AccelCoolDownTime;

    // 減速スキル
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decel")
    int32 DecelTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decel")
    int32 DecelCoolDownTime;

    // 停止スキル
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stop")
    int32 StopTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stop")
    int32 StopCoolDownTime;
};

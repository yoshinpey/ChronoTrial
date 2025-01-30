#include "MyGameInstance.h"
#include "Misc/ConfigCacheIni.h"

void UMyGameInstance::Init()
{
    Super::Init();

    // Configファイルパスの設定
    FString DefaultConfigPath = FPaths::Combine(FPaths::ProjectConfigDir(), TEXT("DefaultGameSettings.ini"));
    ConfigFilePath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Config/GameSettings.ini"));

    // 初回実行時にコピー
    if (!FPaths::FileExists(ConfigFilePath))
    {
        FPlatformFileManager::Get().GetPlatformFile().CopyFile(*ConfigFilePath, *DefaultConfigPath);
    }

    ReadConfigValues();

    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Hello, World!"));

}

void UMyGameInstance::Shutdown()
{
    Super::Shutdown();
    WriteConfigValues();
}

void UMyGameInstance::ReadConfigValues()
{
    // INIから各設定値を読み込み
    GConfig->GetFloat(TEXT("Settings"), TEXT("MouseSensitivity"), MouseSensitivity, ConfigFilePath);
    GConfig->GetFloat(TEXT("Settings"), TEXT("PadSensitivityX"), PadSensitivityX, ConfigFilePath);
    GConfig->GetFloat(TEXT("Settings"), TEXT("PadSensitivityY"), PadSensitivityY, ConfigFilePath);
    GConfig->GetFloat(TEXT("Settings"), TEXT("AimSencePercent"), AimSencePercent, ConfigFilePath);
    GConfig->GetInt(TEXT("Settings"), TEXT("TimerCount"), TimerCount, ConfigFilePath);

    // プレイヤー関係
    GConfig->GetInt(TEXT("Player"), TEXT("HP"), PlayerHP, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("MaxWalkSpeed"), PlayerMaxWalkSpeed, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("Acceleration"), PlayerAcceleration, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("Gravity"), PlayerGravity, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("Friction"), PlayerFriction, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("JumpForce"), PlayerJumpForce, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("AirControl"), PlayerAirControl, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("AirFriction"), PlayerAirFriction, ConfigFilePath);

    // 通常の敵のパラメータを読み込み
    GConfig->GetFloat(TEXT("NormalEnemy"), TEXT("HP"), NormalEnemy.HP, ConfigFilePath);
    GConfig->GetFloat(TEXT("NormalEnemy"), TEXT("MoveSpeed"), NormalEnemy.MoveSpeed, ConfigFilePath);
    //GConfig->GetFloat(TEXT("NormalEnemy"), TEXT("AttackRate"), NormalEnemy.AttackRate, ConfigFilePath);
    GConfig->GetFloat(TEXT("NormalEnemy"), TEXT("AttackPower"), NormalEnemy.AttackPower, ConfigFilePath);

    // 遠距離攻撃の敵のパラメータを読み込み
    GConfig->GetFloat(TEXT("RangedEnemy"), TEXT("HP"), RangedEnemy.HP, ConfigFilePath);
    GConfig->GetFloat(TEXT("RangedEnemy"), TEXT("MoveSpeed"), RangedEnemy.MoveSpeed, ConfigFilePath);
    //GConfig->GetFloat(TEXT("RangedEnemy"), TEXT("AttackRate"), RangedEnemy.AttackRate, ConfigFilePath);
    GConfig->GetFloat(TEXT("RangedEnemy"), TEXT("AttackPower"), RangedEnemy.AttackPower, ConfigFilePath);
    GConfig->GetFloat(TEXT("RangedEnemy"), TEXT("RangedAttackSpeed"), RangedEnemy.RangedAttackSpeed, ConfigFilePath);
    //GConfig->GetFloat(TEXT("RangedEnemy"), TEXT("RangedAttackDist"), RangedEnemy.RangedAttackDist, ConfigFilePath);

    // 銃関係
    GConfig->GetFloat(TEXT("Gun"), TEXT("FireRate"), GunFireRate, ConfigFilePath);
    GConfig->GetFloat(TEXT("Gun"), TEXT("Damage"), GunDamage, ConfigFilePath);
    GConfig->GetInt(TEXT("Gun"), TEXT("Magazine"), GunMagazine, ConfigFilePath);

    // スキル関係の読み込み
    GConfig->GetInt(TEXT("Reverse"), TEXT("ReverseTime"), ReverseTime, ConfigFilePath);
    GConfig->GetInt(TEXT("Reverse"), TEXT("ReverseCoolDownTime"), ReverseCoolDownTime, ConfigFilePath);
    GConfig->GetFloat(TEXT("Reverse"), TEXT("ReverseSpeed"), ReverseSpeed, ConfigFilePath);
    GConfig->GetInt(TEXT("Accel"), TEXT("AccelTime"), AccelTime, ConfigFilePath);
    GConfig->GetInt(TEXT("Accel"), TEXT("AccelCoolDownTime"), AccelCoolDownTime, ConfigFilePath);
    GConfig->GetInt(TEXT("Decel"), TEXT("DecelTime"), DecelTime, ConfigFilePath);
    GConfig->GetInt(TEXT("Decel"), TEXT("DecelCoolDownTime"), DecelCoolDownTime, ConfigFilePath);
    GConfig->GetInt(TEXT("Stop"), TEXT("StopTime"), StopTime, ConfigFilePath);
    GConfig->GetInt(TEXT("Stop"), TEXT("StopCoolDownTime"), StopCoolDownTime, ConfigFilePath);

}

void UMyGameInstance::WriteConfigValues()
{
    GConfig->SetFloat(TEXT("Settings"), TEXT("MouseSensitivity"), MouseSensitivity, ConfigFilePath);
    GConfig->SetFloat(TEXT("Settings"), TEXT("PadSensitivityX"), PadSensitivityX, ConfigFilePath);
    GConfig->SetFloat(TEXT("Settings"), TEXT("PadSensitivityY"), PadSensitivityY, ConfigFilePath);

    GConfig->Flush(false, ConfigFilePath);
}

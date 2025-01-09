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

    GConfig->GetInt(TEXT("Player"), TEXT("HP"), PlayerHP, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("MaxWalkSpeed"), PlayerMaxWalkSpeed, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("Acceleration"), PlayerAcceleration, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("Gravity"), PlayerGravity, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("Friction"), PlayerFriction, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("JumpForce"), PlayerJumpForce, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("AirControl"), PlayerAirControl, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("AirFriction"), PlayerAirFriction, ConfigFilePath);

    GConfig->GetFloat(TEXT("Enemy"), TEXT("HP"), EnemyHP, ConfigFilePath);
    GConfig->GetFloat(TEXT("Enemy"), TEXT("MoveSpeed"), EnemyMoveSpeed, ConfigFilePath);
    GConfig->GetFloat(TEXT("Enemy"), TEXT("AttackRate"), EnemyAttackRate, ConfigFilePath);
    GConfig->GetFloat(TEXT("Enemy"), TEXT("AttackPower"), EnemyAttackPower, ConfigFilePath);
    GConfig->GetFloat(TEXT("Enemy"), TEXT("RangedAttackSpeed"), EnemyRangedAttackSpeed, ConfigFilePath);

    GConfig->GetFloat(TEXT("Gun"), TEXT("FireRate"), GunFireRate, ConfigFilePath);
    GConfig->GetFloat(TEXT("Gun"), TEXT("Damage"), GunDamage, ConfigFilePath);
    GConfig->GetInt(TEXT("Gun"), TEXT("Magazine"), GunMagazine, ConfigFilePath);

    GConfig->GetInt(TEXT("Reverse"), TEXT("ReverseTime"), ReverseTime, ConfigFilePath);
    GConfig->GetInt(TEXT("Reverse"), TEXT("ReverseCoolDownTime"), ReverseCoolDownTime, ConfigFilePath);
    GConfig->GetFloat(TEXT("Reverse"), TEXT("ReverseSpeed"), ReverseSpeed, ConfigFilePath);

}

void UMyGameInstance::WriteConfigValues()
{
    GConfig->SetFloat(TEXT("Settings"), TEXT("MouseSensitivity"), MouseSensitivity, ConfigFilePath);
    GConfig->SetFloat(TEXT("Settings"), TEXT("PadSensitivityX"), PadSensitivityX, ConfigFilePath);
    GConfig->SetFloat(TEXT("Settings"), TEXT("PadSensitivityY"), PadSensitivityY, ConfigFilePath);

    GConfig->Flush(false, ConfigFilePath);
}

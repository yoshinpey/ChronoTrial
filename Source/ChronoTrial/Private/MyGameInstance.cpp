#include "MyGameInstance.h"
#include "Misc/ConfigCacheIni.h"

void UMyGameInstance::Init()
{
    Super::Init();
    ReadConfigValues();

    if (GEngine)
    {
        // 画面の左上に表示する例（色は白、5秒間表示）
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Hello, World!"));
    }

}

void UMyGameInstance::Shutdown()
{
    Super::Shutdown();
    WriteConfigValues();

    if (GEngine)
    {
        // 画面の左上に表示する例（色は白、5秒間表示）
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("ShotDown"));
    }

}

void UMyGameInstance::ReadConfigValues()
{
    // Configファイルのパスを指定
    FString ConfigFilePath = FPaths::Combine(FPaths::ProjectConfigDir(), TEXT("GameSettings.ini"));

    // INIから各設定値を読み込み
    GConfig->GetInt(TEXT("Player"), TEXT("HP"), PlayerHP, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("MaxWalkSpeed"), MaxWalkSpeed, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("Acceleration"), Acceleration, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("Gravity"), Gravity, ConfigFilePath);
    GConfig->GetFloat(TEXT("Player"), TEXT("JumpForce"), JumpForce, ConfigFilePath);

    GConfig->GetFloat(TEXT("Enemy"), TEXT("MoveSpeed"), EnemyMoveSpeed, ConfigFilePath);
    GConfig->GetFloat(TEXT("Enemy"), TEXT("AttackRate"), EnemyAttackRate, ConfigFilePath);
    GConfig->GetFloat(TEXT("Enemy"), TEXT("AttackPower"), EnemyAttackPower, ConfigFilePath);
    GConfig->GetFloat(TEXT("Enemy"), TEXT("HP"), EnemyHP, ConfigFilePath);
    GConfig->GetFloat(TEXT("Enemy"), TEXT("RangedAttackSpeed"), RangedAttackSpeed, ConfigFilePath);

    GConfig->GetFloat(TEXT("Gun"), TEXT("FireRate"), GunFireRate, ConfigFilePath);
    GConfig->GetFloat(TEXT("Gun"), TEXT("Damage"), GunDamage, ConfigFilePath);
    GConfig->GetInt(TEXT("Gun"), TEXT("Magazine"), GunMagazine, ConfigFilePath);

    GConfig->GetFloat(TEXT("Settings"), TEXT("PADSensitivity"), PADSensitivity, ConfigFilePath);
    GConfig->GetFloat(TEXT("Settings"), TEXT("MouseSensitivity"), MouseSensitivity, ConfigFilePath);

    GConfig->GetInt(TEXT("Reverse"), TEXT("ReverseTime"), ReverseTime, ConfigFilePath);
    GConfig->GetInt(TEXT("Reverse"), TEXT("ReverseCoolDownTime"), ReverseCoolDownTime, ConfigFilePath);
    GConfig->GetFloat(TEXT("Reverse"), TEXT("ReverseSpeed"), ReverseSpeed, ConfigFilePath);

}

void UMyGameInstance::WriteConfigValues()
{
    FString ConfigFilePath = FPaths::Combine(FPaths::ProjectConfigDir(), TEXT("GameSettings.ini"));

    GConfig->SetFloat(TEXT("Settings"), TEXT("PADSensitivity"), 1.2f, ConfigFilePath);
    GConfig->SetFloat(TEXT("Settings"), TEXT("MouseSensitivity"), 2.0f, ConfigFilePath);

    GConfig->Flush(false, ConfigFilePath);

    UE_LOG(LogTemp, Log, TEXT("Settings saved to %s"), *ConfigFilePath);
}

# Breaker Project Analysis

Breaker는 Unreal Engine을 기반으로 한 3인칭 슈팅/액션 게임 프로토타입입니다. 이 프로젝트는 체계적인 캐릭터 상태 관리, 무기 시스템, 그리고 데이터 기반의 UI 구조를 갖추고 있습니다.

## 📂 프로젝트 구조

### 1. Player (캐릭터 및 컨트롤)
- **`ABreakerCharacter`**: 핵심 플레이어 클래스입니다.
    - **이동 및 액션**: 걷기, 스프린트, 조준(Aim), 사격 기능을 포함합니다.
    - **상태 머신**: `EEquipState`(장착 상태)와 `EActionState`(동작 상태)를 통해 캐릭터의 논리적 상태를 관리합니다.
    - **전투 시스템**: 주무기/보조무기 교체, IK(Inverse Kinematics)를 이용한 자연스러운 무기 파지, 반동(Recoil) 시스템이 구현되어 있습니다.
    - **상호작용**: 월드 아이템을 탐색하고 획득하는 인터랙션 로직이 포함되어 있습니다.
- **`UPlayerStatComponent`**: 플레이어의 체력(HP) 등 스탯 데이터를 관리합니다.
- **`InputConfigData`**: Enhanced Input 시스템을 사용하여 입력 액션을 체계적으로 관리합니다.

### 2. Item & Weapon (아이템 및 무기)
- **`AItemBase`**: 모든 상호작용 가능한 아이템의 최상위 클래스입니다. 아이콘, 이름, 타입, 중첩 가능 여부 등을 정의합니다.
- **`ABaseWeapon`**: `AItemBase`를 상속받으며, 탄약, 발사 속도(RoF), 사거리, 데미지, 이펙트(Muzzle/Impact) 등 전투에 필요한 속성을 가집니다.
- **`BaseWeaponTemplate`**: 실제 무기 구현을 위한 템플릿 역할을 합니다.

### 3. UI (사용자 인터페이스)
- **Widget Controller 패턴**: 데이터와 UI를 분리하기 위해 `WidgetController`를 도입했습니다.
    - **`ABreakerHUD`**: HUD 전체를 관리하며, Overlay 및 Interaction 위젯을 초기화합니다.
    - **`UOverlayWidgetController`**: 체력, 탄약 등 메인 화면 UI에 데이터를 전달합니다.
    - **`UInteractionWidgetController`**: 상호작용 대상 정보 및 진행 상태를 UI에 전달합니다.

### 4. Types (데이터 타입)
- **`BreakerPlayerTypes.h`**: 프로젝트 전반에서 사용되는 구조체와 열거형을 정의합니다.
    - `FPlayerStatData`: 플레이어 스탯 (HP 등)
    - `FAimSetting`: 조준 시 카메라 암 길이, FOV, 민감도 설정
    - `FMovementSetting`: 상태별 이동 속도 설정
    - `EEquipState`: `Unarmed`, `Primary`, `Secondary`
    - `EActionState`: `Idle`, `Equip`, `Holster`, `Firing`, `Dead` 등

## 🛠 주요 특징
- **확장성 있는 아이템 시스템**: `ItemBase` -> `BaseWeapon` 상속 구조를 통해 새로운 아이템이나 무기를 쉽게 추가할 수 있습니다.
- **체계적인 입력 처리**: Enhanced Input을 활용하여 유연한 입력 매핑이 가능합니다.
- **정교한 상태 제어**: `AnimNotifyState`(`ANSSetActionState`, `ANSSetEquipState`)를 사용하여 애니메이션 몽타주 재생 중 캐릭터의 논리적 상태를 정확히 동기화합니다.
- **데이터 중심 UI**: UI 위젯이 직접 캐릭터에 접근하는 대신 `WidgetController`를 거치도록 설계되어 결합도를 낮췄습니다.

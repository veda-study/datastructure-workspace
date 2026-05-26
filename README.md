# 🧱 VEDA C Data Structure ADT Repository

<div align="center">
  <img src="https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white"/>
  <img src="https://img.shields.io/badge/Pattern-OOP%20in%20C-4B32C3?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Build-Makefile-E34F26?style=for-the-badge&logo=cmake&logoColor=white"/>
  <img src="https://img.shields.io/badge/Tools-GDB%20%7C%20Valgrind%20%7C%20cscope-FCC624?style=for-the-badge"/>
</div>

<br>

> **한화 비전 코딩 테스트 스터디의 서브 프로젝트: C 언어 기반 추상 자료형(ADT) 협업 구현**
> 임베디드 및 시스템 프로그래밍 역량 강화를 위해, 밑바닥부터 자료구조를 설계하고 리눅스 환경의 다양한 개발 툴을 활용하여 실무적인 협업을 진행합니다.

---

## 🎯 스터디 진행 방식 및 아키텍처

본 레포지토리는 단순한 자료구조 구현을 넘어, 현업 시스템 프로그래밍의 설계 패턴과 애자일한 협업 방식을 적용합니다.

* **4인 1조 협업 구현:** 하나의 ADT(예: Linked List)에 대해 세미나를 진행한 후, 핵심 기능을 4개로 분할하여 각 멤버가 동시 개발을 진행합니다. (Git Branch 및 Merge Conflict 해결 훈련)
* **내부 헤더 공유:** 파일이 분할된 상태에서의 협업을 위해 `_internal.h` 형태의 내부 헤더를 사용하여 팀원 간 함수 원형을 공유하고 조립합니다.
* **객체지향적 C 설계:** 구조체 임베딩, 함수 테이블(Function Table), 파수꾼 노드(Sentinel Node)를 활용하여 `list->ops->insert()`와 같은 캡슐화된 인터페이스를 구현합니다.

---

## 🚀 단계별 구현 로드맵 (v1 ➔ v2 ➔ v3)

자료구조의 기본기부터 현업 시스템 프로그래밍 기법까지 점진적으로 학습하고 구현하기 위해 세 가지 버전을 차례대로 개발합니다.

### 📍 v1: 기본 자료구조 (Hardcoded Data)
* **목적:** 자료구조의 논리적인 연결, 삽입/삭제 알고리즘, 파수꾼 노드(Sentinel Node) 개념 및 경계 조건(Edge Case) 처리 완벽 숙지.
* **특징:** 노드 내부에 직접 데이터 타입(예: `int`)이 종속된 직관적인 형태입니다.

### 📍 v2: 범용 자료구조 (`void *` Generic)
* **목적:** 동적 메모리 할당, 타입 캐스팅의 이해 및 메모리 누수 방지(`valgrind` 적극 활용).
* **특징:** 데이터부를 `void *`로 선언하여 모든 포인터를 수용할 수 있는 다형성을 제공합니다. 데이터와 노드가 분리되어 발생하는 캐시 지역성(Cache Locality) 저하에 대해 스터디원들과 논의합니다.

### 📍 v3: 시스템 프로그래밍 최적화 (Intrusive List & OOP in C)
* **목적:** 리눅스 커널 수준의 메모리 최적화 및 객체지향적 C 설계(Pimpl 패턴) 경험.
* **특징:**
  * **구조체 임베딩 (Intrusive):** 데이터를 노드가 가리키는 대신, 사용자 정의 데이터 구조체 안에 노드를 포함(Embed)시킵니다. (`container_of` 매크로 활용을 통한 캐시 지역성 극대화)
  * **Ops 테이블 (캡슐화):** 자료구조 조작 함수들을 함수 포인터 구조체(`ops`)로 묶어 내부 구현을 숨기고 다형성 있는 인터페이스를 제공합니다.

---

## 📂 디렉토리 구조 및 역할 분담

팀원들이 각자의 모듈을 책임지고 구현합니다.

| 자료구조 | 담당자 | 상태 | 비고 |
| :--- | :---: | :---: | :--- |
| **Linked List** | 이영민 | 🚧 진행 중 | 파수꾼 노드 적용 필수 |
| **Stack & Queue** | - | 🗓️ 예정 | 배열 및 연결 리스트 기반 두 가지 버전 |

---

## 💡 C 코딩 컨벤션 (Linux Kernel Style)

팀원 간의 코드 일관성과 실무적 접근을 위해 리눅스 커널 코딩 스타일을 베이스로 다음 규칙을 엄격히 준수합니다.

1. **`typedef` 지양 및 명확한 구조체 명명:**
   * "구조체와 포인터를 숨기지 말라"는 리눅스 커널 철학에 따라 `typedef` 사용을 지양하고 항상 `struct` 키워드를 명시합니다.
   * 불필요한 `_t` 접미사를 제거하고 직관적인 명사를 사용합니다. (예: `node_t` ❌ ➔ `struct list_node` ⭕)
2. **반환값 (Return Values):**
   * **성공 시 `0`, 실패 시 `1`** (또는 에러 코드) 반환을 원칙으로 합니다.
   * 단, `is_empty()`, `is_full()`과 같은 논리 판별(Boolean) 함수의 경우 예외적으로 참(`1`), 거짓(`0`) 구조를 따릅니다.
3. **중괄호 위치 (Brace Placement):**
   * **함수:** 여는 중괄호를 다음 줄에 배치합니다.
   * **제어문 (if, for, while 등):** 여는 중괄호를 제어문과 같은 줄에 배치합니다.

---

## 🛠️ 개발 환경 및 활용 툴
원활한 리눅스 환경 개발 및 디버깅을 위해 다음 툴들을 적극 활용합니다.

* **Build System**: `Makefile` (타겟 빌드, 클린, 테스트 자동화)
* **Code Navigation**: `ctags`, `cscope` (심볼 탐색 및 코드 구조 분석)
* **Debugging**: `gdb` (메모리 및 로직 에러 추적)
* **Memory Check**: `valgrind` (Memory Leak 및 잘못된 메모리 참조 검증)

---

## 🚀 빌드 및 실행 가이드

프로젝트 빌드 및 테스트는 `Makefile`을 통해 일괄 관리됩니다.

```bash
# 코드 탐색용 태그 생성
cscope -Rbq

# 전체 프로젝트 빌드
make all

# 디버깅 모드로 빌드
make debug

# 프로그램 실행
./bin/linkedlist_test

# Valgrind를 통한 메모리 누수 검사
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/linkedlist_test

# 빌드 산출물 정리
make clean
```
# 🧱 VEDA C Data Structure ADT Repository

<div align="center">
  <img src="https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white"/>
  <img src="https://img.shields.io/badge/Pattern-OOP%20in%20C-4B32C3?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Build-Makefile-E34F26?style=for-the-badge&logo=cmake&logoColor=white"/>
  <img src="https://img.shields.io/badge/Tools-GDB%20%7C%20Valgrind%20%7C%20cscopes-FCC624?style=for-the-badge"/>
</div>

<br>

> **한화 비전 코딩 테스트 스터디의 서브 프로젝트: C 언어 기반 추상 자료형(ADT) 협업 구현**
> 임베디드 및 시스템 프로그래밍 역량 강화를 위해, 밑바닥부터 자료구조를 설계하고 리눅스 환경의 다양한 개발 툴을 활용하여 실무적인 협업을 진행합니다.

---

## 🎯 스터디 진행 방식 및 아키텍처

본 레포지토리는 단순한 자료구조 구현을 넘어, 현업 시스템 프로그래밍의 설계 패턴과 애자일한 협업 방식을 적용합니다.

* **4인 1조 협업 구현:** 하나의 ADT(예: Linked List)에 대해 세미나를 진행한 후, 핵심 기능을 4개로 분할하여 각 멤버가 동시 개발을 진행합니다. (Git Branch 및 Merge Conflict 해결 훈련)
* **내부 헤더 공유:** 파일이 분할된 상태에서의 협업을 위해 `_internal.h` 형태의 내부 헤더를 사용하여 팀원 간 함수 원형을 공유하고 조립합니다.
* **객체지향적 C 설계:** 구조체 임베딩, 함수 테이블(Function Table), 파수꾼 노드(Sentinel Node)를 활용하여 `list->insert()`와 같은 캡슐화된 인터페이스를 구현합니다.

---

## 📂 디렉토리 구조 및 역할 분담

팀원들이 각자의 모듈을 책임지고 구현합니다.

| 자료구조 | 담당자 | 상태 | 비고 |
| :--- | :---: | :---: | :--- |
| **Linked List (Singly/Doubly)** | 이영민 | 🚧 진행 중 | 파수꾼 노드 적용 필수 |
| **Stack & Queue** | - | 🗓️ 예정 | 배열 및 연결 리스트 기반 두 가지 버전 |

---

## 💡 C 코딩 컨벤션 (Linux Kernel Style)

팀원 간의 코드 일관성을 위해 리눅스 커널 코딩 스타일을 베이스로 다음 규칙을 엄격히 준수합니다.

1. **반환값 (Return Values):**
   * **성공 시 `0`, 실패 시 `1`** (또는 에러 코드) 반환을 원칙으로 합니다.
   * 단, `is_empty()`, `is_full()`과 같은 논리 판별(Boolean) 함수의 경우 예외적으로 참(`1`), 거짓(`0`) 구조를 따릅니다.
2. **구조체 명명 규칙 (Struct Naming):**
   * 구조체 태그에는 `_`를 붙이고, `typedef` 타입명에는 `_t`를 붙입니다.
   * 예시: `typedef struct _node node_t;`
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
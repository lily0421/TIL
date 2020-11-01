## 리덕스와 react-redux 라이브러리 설치

```
yarn add redux react-redux
```

## redux-devtools-extension 사용하고 싶어요

- Redux DevTools는 리덕스 개발자 도구
- 크롬 확장 프로그램으로 설치해 사용 가능

```
yarn add redux-devtools-extension
```

후, 적용

```javascript
import {composeWithDevTools} form 'redux-devtools-extension'
```

브라우저의 크롬 개발자 도구 실행 후 Redux탭 열면 확인 가능
이때, State 버튼에서 리덕스 스토어 내부의 상태 확인 가능

- 리덕스 action사용
  redux-action 라이브러리와 immer라이브러리 활둉

```
yarn add redux-action
```

### Hooks사용

- function 컴포넌트 사용 시

* connet함수 대신

```javascript
const 결과 = useSelector(상태 선택 함수)
```

```javascript
import {useSelector} form 'react-redux'
```

- 액션 디스패치

useDispatch

- 컴포넌트 내부에서 스토어의 내장함수 dispatch사용

```javascript
const dispatch = useDispatch()
dispatch({ type: 'SAMPLE_ACTION' })
```

최적화 사용시, useCallback으로 액션 디스패치 하는 함수 감싸 줌.

```javascript
import {useCallback} form 'react'
```

- 리덕스 스토어
  컴포넌트 내부에서 리덕스 스토어 객체 직접 사용 가능

```javascript
const store = useStore()
store.dispatch({ type: 'SAMPLE_ACTION' })
store.getState()
```

## connect와 Hooks 사용 차이점

- connect
  성능 최적화 가능

  > > 해당 컴포넌트의 부모 컴포넌트가 리렌더링 될 때 해당 컴포넌트의 props가 바뀌지 않으면 리렌더링이 자동으로 방지 되기 때문

- useSelector
  성능 최적화 자동 안됨  
  따라서, React.memo를 컨테이너 컴포넌트에 사용.

"""크레인 인형뽑기 게임"""

def solution(board, moves):
    stack = [] #장바구니
    result = 0 #터뜨려진 인형 개수
    for move in moves:
        for i in range(len(board)):
            if board[i][move-1] != 0 :
                stack.append(board[i][move-1]) #stack에 쌓기
                board[i][move-1]=0
                if len(stack) > 1:
                    if stack[-1] == stack[-2]: #중복제거
                        stack.pop()
                        stack.pop()
                        result += 2
                break
    return result

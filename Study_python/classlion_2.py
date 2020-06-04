"""n번째 소수
소수를 크기 순으로 나열하면 2, 3, 5, 7, 11, 13, ... 과 같이 됩니다.
이 때 100번째 소수까지 구하시면 됩니다."""

# is_prime 함수는 특정 숫자(n)이 들어왔을 때 
# 그 숫자가 소수면 True를 반환하고 아니면 False를 반환하는 함수입니다.
def is_prime(n):
    if n != 1:
        for i in range(2, n):
            if n % i == 0:
                return False
    else :
        return False
    return True

# prime_number_list 함수는 길이(length)가 들어왔을 때
# 그 길이만큼의 소수를 가지고 있는 리스트를 반환하는 함수입니다.
def prime_number_list(length):
        result = []

        i = 1 #모든 숫자
        cnt = 1 #result의 개수
        while True:
            if is_prime(i) == True:
                
                result.append(i)
                cnt = cnt+1
                i = i+1
            if cnt == length:
                break
            i = i+1
        return result

length = int(input('Length? '))
print(prime_number_list(length))

'''빨간색: 620nm 이상 780nm 이하
주황색: 590nm 이상 620nm 미만
노란색: 570nm 이상 590nm 미만
초록색: 495nm 이상 570nm 미만
파란색: 450nm 이상 495nm 미만
남색: 425nm 이상 450nm 미만
보라색: 380nm 이상 425nm 미만
입력
계기판에 표시된 별빛의 파장 
$\lambda$ 가 주어진다. 파장은 항상 정수로 주어지며 단위는 
$\textrm{nm}$이다. 
$(380 \leq \lambda \leq 780)$ 

남색이면 "Indigo", 보라색이면 "Violet"을 출력한다.'''

a=int(input())
if 620 <= a <= 780:
    print('Red')
elif 590 <= a < 620:
    print('Orange')
elif 570 <= a < 590:
    print('Yellow')
elif 495 <= a < 570:
    print('Green')
elif 450 <= a < 495:
    print('Blue')
elif 425 <= a < 450:
    print('Indigo')
elif 380 <= a < 425:
    print('Violet')

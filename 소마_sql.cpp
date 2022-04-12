/*
소마 서점 전산 오류
소마의 실수로 전산 오류가 발생해서 데이터베이스 내에 문제가 발생하였다.

다행히 소마가 발 빠르게 대응한 덕분에 데이터베이스 내에 발생한 문제점들을 빠르게 찾을 수 있었다.

발견된 문제점은 두가지이며 이를 토대로 데이터베이스 내에 잘못된 내용이 얼마나 있는지 확인하려 한다.

판매하고 있지 않은 도서가 판매된 기록이 있음
서점을 열지 않은 기간 동안 고객이 도서를 구매한 기록이 있음
소마 서점에서 사용 중인 데이터베이스의 테이블은 아래와 같다.


테이블 명	설명
library	판매 중인 책의 정보
orderInfo	서적의 판매 정보


지시사항에 따라 SQL 문을 작성하시오.

지시사항
library와 orderInfo 테이블을 활용하여 아래 조건 중 한 가지라도 성립하는 내용을 찾고 buyer_id, buy_date, book_name ,price 컬럼에 대한 쿼리 결과를 구매일을 기준으로 오름차순 정렬하여 출력하시오.
(날짜는 yyyy-mm-dd 형식으로 되어있다.)

책 이름(book_name)이 Looking with Elice인 도서
책 구매일(buy_date)이 2020-07-27부터 2020-07-31까지인 모든 도서
출력 예시
아래의 예시는 문제를 푸는데 참고할 수 있는 예시입니다. 최종적으로 제출해야 하는 답안과는 관계가 없습니다.

library와 orderInfo 테이블이 아래와 같이 구성되어있다고 가정한다.

library 테이블 구성


book_id	book_name	pulisher	price
A1	Looking with Elice	elice	20000
B1	Challenge! Python	elice	12000
orderInfo 테이블 구성


order_no	buyer_id	book_id	buy_date
1	rabbit	A1	2020-07-20
2	cat	B1	2020-07-28
3	bird	B1	2020-06-28
이후 SQL 실행 결과는 아래와 같다.


buyer_id	buy_date	book_name	price
rabbit	2020-07-20	Looking with Elice	20000
cat	2020-07-28	Challenge! Python	12000


Tips!
주어진 데이터베이스, 테이블을 삭제하거나 추가로 생성하는 경우 채점 과정 중 오답 처리가 될 수 있습니다.
*/
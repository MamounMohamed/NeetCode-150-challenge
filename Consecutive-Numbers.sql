# Write your MySQL query statement below
select distinct num as ConsecutiveNums from (
    select num ,lag(num,1) over(order by id) as prevNum1 , lag(num,2) over (order by id) as prevNum2 from logs 
)  as subQuery where num = prevNum1 and num= prevNum2 
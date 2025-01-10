# Write your MySQL query statement below
with cte as (
    select requester_id as temp from RequestAccepted
    union all
    select accepter_id as temp from RequestAccepted
)
select temp as id, count(temp) as num
from cte 
group by temp
order by count(temp) desc limit 1
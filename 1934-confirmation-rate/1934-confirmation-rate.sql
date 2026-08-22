# Write your MySQL query statement below
select s.user_id,round(
       case 
          when c.action is null then 0.00
          else count(
            case 
               when c.action = 'confirmed' then 1
               else null
            end) / count(*)
       end,2) as confirmation_rate
from signups s
left join confirmations c
on s.user_id = c.user_id
group by s.user_id
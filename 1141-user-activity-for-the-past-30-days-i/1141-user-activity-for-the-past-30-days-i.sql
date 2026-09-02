# Write your MySQL query statement below
select activity_date day,count(distinct user_id) active_users
from activity
group by activity_date
having activity_date > date_sub("2019-07-27",interval 30 day) and activity_date <= "2019-07-27";

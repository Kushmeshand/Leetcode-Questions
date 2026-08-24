# Write your MySQL query statement below
select round(
       count(distinct e.player_id) / count(*) ,2) fraction
from(
    select a.player_id,min(a.event_date) imlogin
    from activity a
    group by player_id
) d
left join activity e
on d.player_id = e.player_id and datediff(event_date,imlogin) = 1

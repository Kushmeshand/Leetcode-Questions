# Write your MySQL query statement below
select e.name
from employee e
join employee f
on e.id = f.managerid
group by f.managerid
having count(*) >= 5

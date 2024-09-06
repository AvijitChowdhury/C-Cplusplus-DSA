-- 
Select UPPER(first_name)
from employees;
ALTER TABLE Employee
MODIFY COLUMN Email VARCHAR(50);
Select upper(first_name)
from employee
where salary<500
having max(salary=6000);
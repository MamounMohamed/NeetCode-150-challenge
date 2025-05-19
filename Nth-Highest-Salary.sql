
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE offsetVal INT;
  SET offsetVal = N - 1;

  RETURN (
    select * from 
    (
        select distinct salary 
        from Employee order by salary desc 
        limit 1 offset offsetVal
    ) as getNthHighestSalary(N)
  );
END 

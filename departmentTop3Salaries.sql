# Write your MySQL query statement below
SELECT
    Department,
    Employee,
    Salary
FROM (
    SELECT
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        DENSE_RANK() OVER (
            PARTITION BY e.departmentId
            ORDER BY e.salary DESC
        ) AS salary_rank
    FROM Employee e
    JOIN Department d
        ON e.departmentId = d.id
) ranked
WHERE salary_rank <= 3;
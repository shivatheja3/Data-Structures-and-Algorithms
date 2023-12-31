# Write your MySQL query statement below
# select 'Low salary' as category, count(*) as accounts_count from Accounts where income<20000
# union
# select 'Average salary' as category, count(*) as accounts_count from Accounts where income between 20000 and 50000
# union
# select 'High salary' as category, count(*) as accounts_count from Accounts where income>50000;
SELECT 'Low Salary' AS category, COUNT(*) AS accounts_count 
FROM Accounts 
WHERE income < 20000
UNION
SELECT 'Average Salary' AS category, COUNT(*) AS accounts_count 
FROM Accounts 
WHERE income BETWEEN 20000 AND 50000
UNION
SELECT 'High Salary' AS category, COUNT(*) AS accounts_count 
FROM Accounts 
WHERE income > 50000;
# Write your MySQL query statement below
SELECT Person.FirstName as FirstName, Person.LastName as LastName, City, State from Person left join Address on Person.PersonId=Address.PersonId
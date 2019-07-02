CREATE TABLE if not exists salary(id int, name varchar(100), sex char(1), salary int);
TRUNCATE TABLE salary;
INSERT INTO salary (id, name, sex, salary) values ('1', 'A', 'm', '2500');
INSERT INTO salary (id, name, sex, salary) values ('2', 'B', 'f', '1500');
INSERT INTO salary (id, name, sex, salary) values ('3', 'C', 'm', '5500');
INSERT INTO salary (id, name, sex, salary) values ('4', 'D', 'f', '500');

/*BEGIN ANS*/
UPDATE salary SET sex = IF (sex = 'm', 'f', 'm');
/*END ANS*/

SELECT * FROM salary;

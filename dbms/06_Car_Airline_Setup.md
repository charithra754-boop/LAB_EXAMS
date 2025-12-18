# 🚗 Program 6: Car & Airline Database Setup

## Part A: Car Ownership

### 🔄 Order of Creation
1. `person`
2. `car`
3. `owns` (depends on `person`, `car`)

### 🛠️ Table Creation
```sql
create table person (
    driver_id varchar(20) primary key,
    name varchar(100),
    address varchar(255)
);

create table car (
    regno varchar(20) primary key,
    model varchar(50),
    year int
);

create table owns (
    driver_id varchar(20),
    regno varchar(20),
    primary key (driver_id, regno),
    foreign key (driver_id) references person(driver_id) on delete cascade,
    foreign key (regno) references car(regno) on delete cascade
);
```

### 📥 Data Insertion
```sql
insert into person values 
    ('d1', 'john', 'bangalore'),
    ('d2', 'alex', 'mysore'),
    ('d3', 'ravi', 'bangalore');

insert into car values 
    ('ka01-1234', 'swift', 2018),
    ('ka02-5678', 'innova', 2020),
    ('ka03-9012', 'honda city', 2019);

insert into owns values 
    ('d1', 'ka01-1234'), -- john owns swift
    ('d1', 'ka02-5678'), -- john owns innova too
    ('d2', 'ka03-9012'); -- alex owns city

-- ravi owns nothing (useful for checking left join)
```

---

## Part B: Airline Database

### 🔄 Order of Creation
1. `aircraft`
2. `employee_airline`
3. `certified` (depends on `aircraft`, `employee_airline`)

### 🛠️ Table Creation
```sql
create table aircraft (
    aircraft_id int primary key,
    aircraft_name varchar(100),
    cruising_range int
);

create table employee_airline (
    emp_id int primary key,
    ename varchar(100),
    salary decimal(10, 2)
);

create table certified (
    emp_id int,
    aircraft_id int,
    primary key (emp_id, aircraft_id),
    foreign key (emp_id) references employee_airline(emp_id) on delete cascade,
    foreign key (aircraft_id) references aircraft(aircraft_id) on delete cascade
);
```

### 📥 Data Insertion
```sql
insert into aircraft values 
    (101, 'boeing 747', 5000),
    (102, 'airbus a320', 3000),
    (103, 'cessna', 500);

insert into employee_airline values 
    (1, 'pilot a', 150000),
    (2, 'pilot b', 120000),
    (3, 'steward c', 50000),
    (4, 'pilot d', 150000); -- tie for highest salary


insert into certified values 
    (1, 101), -- pilot a flies boeing
    (1, 102), -- pilot a flies airbus
    (2, 103); -- pilot b flies cessna

-- steward c and pilot d are not certified (useful for query #2)
```

# 🎓 Program 2: College Database Setup

## 🔄 Order of Creation
1. `student`
2. `semsec`
3. `class` (depends on `student`, `semsec`)
4. `subject`
5. `iamarks` (depends on `student`, `semsec`, `subject`)

## 🛠️ Table Creation

```sql
create table student (
    usn varchar(20) primary key,
    sname varchar(100),
    address varchar(255),
    phone varchar(20),
    gender char(1)
);

create table semsec (
    ssid varchar(20) primary key,
    sem int,
    sec char(1)
);

create table class (
    usn varchar(20),
    ssid varchar(20),
    primary key (usn, ssid),
    foreign key (usn) references student(usn) on delete cascade,
    foreign key (ssid) references semsec(ssid) on delete cascade
);

create table subject (
    subcode varchar(20) primary key,
    title varchar(100),
    sem int,
    credits int
);

create table iamarks (
    usn varchar(20),
    subcode varchar(20),
    ssid varchar(20),
    test1 int,
    test2 int,
    test3 int,
    finalia decimal(5, 2),
    primary key (usn, subcode, ssid),
    foreign key (usn) references student(usn) on delete cascade,
    foreign key (subcode) references subject(subcode) on delete cascade,
    foreign key (ssid) references semsec(ssid) on delete cascade
);
```

## 📥 Data Insertion

```sql
-- 1. semsec (semester & sections)
insert into semsec values 
    ('4c', 4, 'c'),
    ('4b', 4, 'b'),
    ('8a', 8, 'a');

-- 2. students
insert into student values 
    ('1bi15cs101', 'alice', 'bangalore', '9900112233', 'f'),
    ('1bi15cs102', 'bob', 'mysore', '9900223344', 'm'),
    ('1bi15cs103', 'charlie', 'bangalore', '9900334455', 'm');

-- 3. class (mapping students to semsec)
insert into class values 
    ('1bi15cs101', '4c'), -- alice in 4th sem c section
    ('1bi15cs102', '4c'), -- bob in 4th sem c section
    ('1bi15cs103', '4b');

-- 4. subjects
insert into subject values 
    ('15cs41', 'maths', 4, 4),
    ('15cs42', 'dbms', 4, 4),
    ('15cs43', 'os', 4, 3);

-- 5. iamarks
-- alice marks
insert into iamarks values 
    ('1bi15cs101', '15cs41', '4c', 18, 15, 20, 0), 
    ('1bi15cs101', '15cs42', '4c', 15, 18, 12, 0);

-- bob marks
insert into iamarks values ('1bi15cs102', '15cs41', '4c', 10, 12, 12, 0);
```

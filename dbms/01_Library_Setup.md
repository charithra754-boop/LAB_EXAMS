# 📚 Program 1: Library Database Setup

## 🔄 Order of Creation
1. `publisher`
2. `library_branch`
3. `book` (depends on `publisher`)
4. `book_authors` (depends on `book`)
5. `book_copies` (depends on `book`, `library_branch`)
6. `book_lending` (depends on `book`, `library_branch`)

## 🛠️ Table Creation

```sql
create table publisher (
    name varchar(100) primary key,
    address varchar(255),
    phone varchar(20)
);

create table library_branch (
    branch_id int primary key,
    branch_name varchar(100),
    address varchar(255)
);

create table book (
    book_id int primary key,
    title varchar(255),
    publisher_name varchar(100),
    pub_year int,
    foreign key (publisher_name) references publisher(name) on delete cascade
);

create table book_authors (
    book_id int,
    author_name varchar(100),
    primary key (book_id, author_name),
    foreign key (book_id) references book(book_id) on delete cascade
);

create table book_copies (
    book_id int,
    branch_id int,
    no_of_copies int,
    primary key (book_id, branch_id),
    foreign key (book_id) references book(book_id) on delete cascade,
    foreign key (branch_id) references library_branch(branch_id) on delete cascade
);

create table book_lending (
    book_id int,
    branch_id int,
    card_no int,
    date_out date,
    due_date date,
    primary key (book_id, branch_id, card_no),
    foreign key (book_id) references book(book_id) on delete cascade,
    foreign key (branch_id) references library_branch(branch_id) on delete cascade
);
```

## 📥 Data Insertion

```sql
-- 1. publishers
insert into publisher values 
    ('pearson', 'new york', '9875462530'),
    ('mcgraw hill', 'california', '9875462531'),
    ('sapna', 'bangalore', '9875462532');

-- 2. branches
insert into library_branch values 
    (10, 'main branch', 'bangalore'),
    (11, 'city branch', 'mysore'),
    (12, 'campus branch', 'mangalore');

-- 3. books
insert into book values 
    (101, 'dbms', 'pearson', 2017),
    (102, 'operating systems', 'mcgraw hill', 2016),
    (103, 'networks', 'pearson', 2018),
    (104, 'algorithms', 'sapna', 2019),
    (105, 'java', 'mcgraw hill', 2015);

-- 4. authors
insert into book_authors values 
    (101, 'navathe'),
    (102, 'galvin'),
    (103, 'tanenbaum'),
    (104, 'cormen'),
    (105, 'herbert schildt');

-- 5. book copies
insert into book_copies values 
    (101, 10, 10),
    (101, 11, 5),
    (102, 10, 8),
    (102, 11, 2),
    (103, 12, 15);

-- 6. lending (note: dates chosen to satisfy query #2: jan 2017 - jun 2017)
-- card 1 has > 3 books in the range
insert into book_lending values 
    (101, 10, 1, '2017-01-15', '2017-02-15'),
    (102, 10, 1, '2017-02-20', '2017-03-20'),
    (103, 11, 1, '2017-03-10', '2017-04-10'),
    (104, 11, 1, '2017-04-05', '2017-05-05'); 

-- card 2 has < 3 books
insert into book_lending values (101, 10, 2, '2017-01-10', '2017-02-10');
```

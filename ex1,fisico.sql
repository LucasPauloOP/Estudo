/*exercicio 1 livraria*/
/*definicao de tipagem*/
varchar livro(50),
varchar autor(30),
char sexo(1),
varchar numero de paginas(1000),
varchar editora(100),
varchar preco(1000),
char uf(2),
int ano(5),

/*criacao do banco de dados*/
create database livraria;

/*criacao da tabela*/
create table livros(
livro varchar(50),
autor varchar(30),
sexo char(1),
paginas varchar(1000),
editora varchar (100),
preco varchar(1000),
uf char(2),
ano int(5)
);
 insert into livros(livro,autor,sexo,paginas,editora,preco,uf,ano)
 value ('Cavaleiro Real','Ana Claudia','F','465','atlas','49,90'
 ,'RJ',2009);
 
insert into livros(livro,autor,sexo,paginas,editora,preco,uf,ano)
value('SQL para leigos','João Nunes','M','450','Addison','98','SP',2018);

insert into livros(livro,autor,sexo,paginas,editora,preco,uf,ano)
value('Receitas Caseiras','Celia Tavares','M','210','Atlas','45','RJ',2008);

insert into livros(livro, autor,sexo,paginas,editora,preco,uf,ano)
value('Pessoas efetivas','Eduardo Santos','M','390','Beta','78,99','RJ',2018);

insert into livros(livro,autor,sexo,paginas,editora,preco,uf,ano)
value('Habitos Saudáveis','Eduardo Santos','M','630','Beta','150,98','RJ',2019);

insert into livros(livro,autor,sexo,paginas,editora,preco,uf,ano)
value('A Casa Marrom','Hermes Macedo','M','250','Bubba','60','MG',2016);

insert into livros(livro,autor,sexo,paginas,editora,preco,uf,ano)
value('Estacio Querido','Geraldo Franciso','M','310','insignia','100','ES',2015);

insert into livros(livro,autor,sexo,paginas,editora,preco,uf,ano)
value('Para sempre amigas','leda Silva','F','510','insignia','78,98','ES',2011);

insert into livros(livro,autor,sexo,paginas,editora,preco,uf,ano)
value('Copas Inesqueciveis','Marco Alcantra','M','200','Larson','130,98','RS',2018);

insert into livros(livro,autor,sexo,paginas,editora,preco,uf,ano)
value('O poder da mente','Clara Mafra','F','120','Continental','56,58','SP',2017);

/*trazer os dados*/
select *from livros;

/*trazer nome do livro e editora*/
select livro,editora from livros;

/*trazer o nome do livro e a uf dos livros publicados por autores do sexo masculino*/
select livro,uf from livros
where sexo ='M';

/*trazer o nome do livro e o numero de paginas dos livros publicados por autores do sexo feminino*/
select livro,paginas from livros
where sexo ='f';

/*Trazer os valores de livros da edistoras de sp*/
select preco from livros
where uf = 'SP';

/*trazer os dados dos autores do sexo masculino que tiveram livros publicados por sao paulo ou rio de janeiro*/
select livro,preco,autor,editora,uf,paginas,ano,sexo from livros
where sexo = 'M'and (uf ='SP'or uf='RJ');































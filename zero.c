#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Status{NAFILA, SOLUCIONANDO, ENCERRADO};

// declaracao de tipos 

typedef struct Telefone{
    int cod;
    char numero[15];
}Telefone;

typedef struct Email{
    int cod;
    char email[50];
}Email;

typedef struct Endereco{
    int cod;
    char pais[30];
    char estado[30];
    char cidade[30];
    char bairro[50];
    char rua[50];
    int numero;
    char Complemento[20];
    char cep[15];
}Endereco;

typedef struct Usuario{
    int ativo;
    int cod;
    char nome[30], sobrenome[30], cpf[15] ;
    Telefone *telefone1, *telefone2;
    Email *email;
    Endereco *endereco;
    char login[30], senha[30];
    struct Usuario *prox;
    struct Usuario *anterior;
}Usuario;

typedef struct Data{
    char ano[5];
    char mes[3];
    char dia[3];
}Data;

typedef struct Denuncia{
    int code;
    Data *postagem;
    Data *encerramento;
    Endereco *endereco;
    Usuario *usuario;
    char descricao[500];
    enum Status status;
    struct Denuncia *prox;
    struct Denuncia *anterior;
}Denuncia;

typedef struct FilaDenuncias{
    int tamanho;
    int code;
    Denuncia *inicio;
    Denuncia *fim;
}FilaDenuncias;

typedef struct FilaUsuarios{
    int tamanho;
    Usuario *primeiro;
    Usuario *ultimo;
}FilaUsuarios;

// declaracao de funcoes

int gerarCodigoUsuario();
int gerarCodigoDenuncia();

int compararNome(Usuario *, char[30]);
int compararSobrenome(Usuario *, char[30]);
int compararCpf(Usuario *, char[30]);
int compararCodigo(Usuario *, int);




Usuario * criarUsuario(char[30], char[30], char[15], Telefone *, Telefone *, Email *, Endereco *, char[30], char[30]);
Telefone * criarTelefone(char[15]);
Email * criarEmail(char[50]);
Endereco * criarEndereco(char[30], char[30], char[30], char[50], char[50], int, char[20], char[15]);
Data * criarData(char[5], char[3], char[3]);
Denuncia * criarDenuncia(Data*, Endereco *, Usuario *);
FilaDenuncias * criarFilaDenuncias();
FilaUsuarios * criarFilaUsuarios();


//funcoes de print

void pedirNomeUsuario();
void pedirSobreNomeUsuario();
void pedirCpfUsuario();
void pedirLoginUsuario();
void pedirSenhaUsuario();
void pedirTelefone();
void pedirEmail();
void pedirEndereco();
void pedirPais();
void pedirEstado();
void pedirCidade();
void pedirBairro();
void pedirRua();
void pedirNumero();
void pedirComplemento();
void pedirCep();
void pedirData();
void pedirAno();
void pedirMes();
void pedirDia();


void alterarUsuario(Usuario *);
void alterarTelefone(Telefone *, int );
void alterarEmail(Email *);
void alterarEndereco(Endereco *);
void alterarData(Data *);
void alterarDenuncia(Denuncia *);
void alterarFilaDenuncias(FilaDenuncias *);

void alterarDataPostagem(Denuncia *);
void alterarDataEncerramento(Denuncia *);
void alterarStatus(Denuncia *); 

void alterarCodeUsuario(Usuario *, int);
void alterarCodeTelefone(Telefone *, int);
void alterarCodeEmail(Email *, int);
void alterarCodeEndereco(Endereco *, int);
void alterarCodeDenuncia(Denuncia *, int);
void alterarCodeFilaDenuncias(FilaDenuncias *, int);

void alterarUsuarioComParametros(Usuario*, char[30], char[30], char[15], Telefone *, Telefone *, Email *, Endereco *, char[30], char[30]);
void alterarTelefoneComParametros(Telefone *, char[15]);
void alterarEmailComParametros(Email *, char[50]);
void alterarEnderecoComParametros(Endereco *,char[30], char[30], char[30], char[50], char[50], int, char[20], char[15]);
void alterarDataComParametros(Data *, char[5], char[3], char[3]);
void alterarDenunciaComParametros(Denuncia *, Data*, Data*, Endereco *, Usuario *);
void alterarFilaDenunciasComParametros(FilaDenuncias *);

void freeUsuario(Usuario *);
void freeTelefone(Telefone *);
void freeEmail(Email *);
void freeEndereco(Endereco *);
void freeFilaDenuncias(FilaDenuncias *);
void freeEnd(Endereco *);

void exibirTelaNovoUsuario();
void exibirTelaNovoTelefone();
void exibirTelaNovoEmail();
void exibirTelaNovoEndereco();
void exibirTelanovaDenuncia();
void exibirTelaNovaData();



void inserirDenunciaNaFilaDenuncias(Denuncia *);
void inserirUsuarioNaFilaUsuario(Usuario *);

int FilaDenunciasVazia(FilaDenuncias *);
int FilaUsuariosVazia(FilaUsuarios *);

int FilaDenunciasCheia(FilaDenuncias *);
int FilaUsuariosCheia(FilaUsuarios *);

Denuncia * pegarProximaDenuncia(FilaDenuncias *);
Denuncia * pegarTodasAsDenuncias(Denuncia *, FilaDenuncias *);
Usuario * pegarProximoUsuario(FilaUsuarios *);
Usuario * pegarTodosOsUsuarios(Usuario *, FilaUsuarios *);

int recuperarStatusDenuncias(int);
Denuncia * recuperarDenuncia(int cod);
Usuario * recuperarUsuario(int cod);
void esvasiarFilaDenuncias();
void removerDenuncia(Denuncia *);
void removerProximaDenuncia();
void removerProximoUsuario();
void removerDenunciasDoUsuario(Usuario *);

int verificarDenunciaNulo(Denuncia *);
int verificarUsuarioNulo(Usuario *);

void imprimirUsuario(Usuario *);
void imprimirTelefone(Telefone *);
void imprimirEmail(Email *);
void imprimirEndereco(Endereco *);
void imprimirData(Data *);
void imprimirDenuncia(Denuncia *d);
void imprimirStatus(Denuncia *);

void imprimirTodasAsDenuncias(Denuncia *);
void imprimirTodasAsDenunciasUsuario(Denuncia *, Usuario *);
void imprimirDenunciaComFiltro(Denuncia *, int , char [50]);
void imprimirTodasAsDenunciasComFiltro(Denuncia *, int , char [50]);
void imprimirFilaDenuncias();

void imprimirTodosOsUsuarios(Usuario *);
void imprimirUsuarioComFiltro(Usuario *, int , char [50], int cod);
void imprimirTodosOsUsuariosComFiltro(Usuario *, int , char [50], int );
void imprimirFilaUsuarios();


void exibirTelaInicial();
void exibirCabecalho();
void exibirTelaLogin();
void exibirTelaCadastro();
void exibirTelaAtividades();
void exibirTelaConsultarDenuncias();
void exibirTelaConsultarUsuario();
void exibirTelaGerenciarUsuarios();
void exibirTelaGerenciarDenuncias();
void exibirTelaAlterarUsuario();
void exibirTelaAlterarDenuncia();
void exibirTelaGerenciarFilaDenuncias();
void exibirTelaGerenciarFilaUsuarios();



int exibirOpcoesTelaAtividades();
int exibirOpcoesTelaInicial();
int exibirTelaOpcoesConsultarDenuncias();
int exibirTelaOpcoesAlterarDenuncia();
int exibirTelaOpcoesConsultarUsuario();
int exibirTelaOpcoesAlterarUsuario();
int exibirTelaOpcoesFiltrarUsuarios();
int exibirTelaOpcoesFiltrarDenuncias();
int exibirTelaOpcoesGerenciarUsuarios();
int exibirTelaOpcoesGerenciarDenuncia();
int exibirTelaOpcoesGerenciarFilaDenuncias();
int exibirTelaOpcoesTelaInicial();
int exibirTelaOpcoesGerenciarfilaUsuarios();

void exibirVisaoGerral();
int autenticarUsuario(Usuario *, char [30], char [30]);
void filtrarDenuncias();
void filtrarUsuarios();
void teste();


// declaracao de variaveis

int usuariosCadastrados;
Usuario *usuario;
Usuario *usuarioLogado;
Denuncia *denuncia;
FilaDenuncias *filaDenuncias;
FilaUsuarios *filaUsuarios;
Usuario **usuarios;
int codigoUsuario;
int codigoDenuncia;

//variaveis auxiliares

char nome[30];
char sobrenome[30];
char cpf[15];
char telefone1[15];
char telefone2[15];
char numeroTelefone[15];
char email[50];
char login[30];
char senha[30];
char pais[30];
char estado[30];
char cidade[30];
char bairro[50];
char rua[50];
int numero;
char complemento[20];
char cep[25];

char ano[5];
char mes[3];
char dia[3];

char descricao[500];

Data *encerramento;
// metodos de testes


void teste(){ 
    
    encerramento = criarData("0000", "00", "00");

    Email *email;
    Telefone *telefone1;
    Telefone *telefone2;
    Endereco *endereco;
    Usuario *usuario; 
    
    telefone1 = criarTelefone("(19) 45638745");
    telefone2 = criarTelefone("(19) 46556665");
    email = criarEmail("jhonatansares62@gmail.com");
    endereco = criarEndereco("Brasil", "Sao Paulo", "Campinas", "Parque via Norte","Tucuman", 3543, "casa", "356345");
    usuario = criarUsuario("jhonatan", "soares", "123456", telefone1, telefone2, email, endereco, "jhonatan", "1" );

    Email *email1;
    Telefone *telefone11;
    Telefone *telefone21;
    Endereco *endereco1;
    Usuario *usuario1; 

    telefone11 = criarTelefone("(19) 585686858");
    telefone21 = criarTelefone("(19) 567888665");
    email1 = criarEmail("anapaulavitorino@gmail.com");
    endereco1 = criarEndereco("Argentina", "Sao Paulo", "Campinas", "Parque via Norte","acacias", 45, "casa", "456456");
    usuario1 = criarUsuario("Andre", "da silva", "4563463", telefone11, telefone21, email1, endereco1, "Andre", "2" );
 
    Email *email2;
    Telefone *telefone12;
    Telefone *telefone22;
    Endereco *endereco2;
    Usuario *usuario2; 

    telefone12 = criarTelefone("(19) 45638745");
    telefone22 = criarTelefone("(19) 46556665");
    email2 = criarEmail("samuel43@gmail.com");
    endereco2 = criarEndereco("Brasil", "Sao Paulo", "Sorocaba", "Parque via Norte","Tucuman", 3543, "casa", "356345");
    usuario2 = criarUsuario("samuel", "da cunha", "4554335", telefone12, telefone22, email2, endereco2, "samuel", "3" );

    Email *email3;
    Telefone *telefone13;
    Telefone *telefone23;
    Endereco *endereco3;
    Usuario *usuario3; 

    telefone13 = criarTelefone("(19) 53566565");
    telefone23 = criarTelefone("(19) 464567776");
    email3 = criarEmail("sophia54@gmail.com");
    endereco3 = criarEndereco("Brasil", "Curitiba", "Campinas", "Parque via Norte","Tucuman", 3543, "casa", "356345");
    usuario3 = criarUsuario("Camila", "gonzales", "355366", telefone13, telefone23, email3, endereco3, "camila", "4" );
  
    Data *data;
    Data *data1;
    Data *data2;
    Data *data3;
    data = criarData("2020", "10", "23");
    data1 = criarData("1919", "20", "03");
    data2 = criarData("1919", "20", "03");
    data3 = criarData("1919", "20", "03");
    Denuncia *denuncia;
    Denuncia *denuncia1;
    Denuncia *denuncia2;
    Denuncia *denuncia3;
    denuncia = criarDenuncia(data, endereco, usuario);    
    denuncia1 = criarDenuncia(data1,endereco1, usuario1);
    denuncia2 = criarDenuncia(data2,endereco2, usuario2);
    denuncia3 = criarDenuncia(data3,endereco3, usuario3);
    inserirDenunciaNaFilaDenuncias(denuncia); 
    inserirDenunciaNaFilaDenuncias(denuncia1); 
    inserirDenunciaNaFilaDenuncias(denuncia2);
    inserirDenunciaNaFilaDenuncias(denuncia3);

}

// implementacao das funcoes

int gerarCodigoUsuario(){
    codigoUsuario++;
    return codigoUsuario;
}
int gerarCodigoDenuncia(){
    codigoDenuncia++;
    return codigoDenuncia;
}


int compararNome(Usuario *u, char nome[30]){
    int resultado = strncmp(u -> nome, nome, 30);
    return resultado;
}
int compararSobrenome(Usuario *u, char sobrenome[30]){
    int resultado = strncmp(u -> sobrenome, sobrenome, 30);
    return resultado;
}
int compararCpf(Usuario *u, char cpf[15]){
    int resultado = strncmp(u -> cpf, cpf, 15);
    return resultado;
}
int compararCodigo(Usuario *u, int cod){
    if(u -> cod == cod){
        return 0;
    }else{
        return 1;
    }
}
int compararLogin(Usuario *u, char login[30]){
    int resultado = strncmp(u -> login, login, 30);
    return resultado;
}
int compararSenha(Usuario *u, char senha[30]){
    int resultado = strncmp(u -> senha, senha, 30);
    return resultado;
}


Usuario * criarUsuario(char nome[30], char sobrenome[30], char cpf[15], Telefone *t1, Telefone *t2, Email *email, Endereco *end, char login[30], char senha[30]){
    Usuario *u;
    u = (Usuario*)malloc(sizeof(Usuario));
    u -> cod = gerarCodigoUsuario();
    strcpy(u -> nome, nome);
    strcpy(u -> sobrenome, sobrenome);
    strcpy(u -> cpf, cpf);
    strcpy(u -> login, login);
    strcpy(u -> senha, senha);
    u -> telefone1 = t1;
    u -> telefone2 = t2;
    u -> email = email;
    u -> endereco = end;
    u -> prox = NULL;
    u -> anterior = NULL;

    inserirUsuarioNaFilaUsuario(u);
    return u;
}
Telefone * criarTelefone(char numero[15]){
    Telefone *t;
    t =(Telefone*) malloc(sizeof(Telefone));
    t -> cod = 1;
    strcpy(t -> numero, numero);
    return t;
}
Email * criarEmail(char email[50]){
    Email *e;
    e = (Email*)malloc(sizeof(Email));
    e -> cod = 1;
    strcpy(e -> email, email);
    return e;
}
Endereco * criarEndereco(char pais[30],char estado[30], char cidade[30], char bairro[50], char rua[50], int numero, char complemento[20], char cep[15]){
    Endereco *e;
    e = (Endereco*)malloc(sizeof(Endereco));
    e -> cod = 1;   
    strcpy(e -> pais, pais);  
    strcpy(e -> estado, estado);  
    strcpy(e -> cidade, cidade);  
    strcpy(e -> bairro, bairro);  
    strcpy(e -> rua, rua);
    e -> numero = numero; 
    strcpy(e -> Complemento, complemento);
    strcpy( e -> cep, cep);
    return e;
}
Data * criarData(char ano[5], char mes[3], char dia[3]){
    Data *d;
    d = (Data*)malloc(sizeof(Data));
    strcpy(d -> ano, ano);
    strcpy(d -> mes, mes);
    strcpy(d -> dia, dia);
    return d;
}
Denuncia * criarDenuncia(Data *postagem, Endereco *end, Usuario *usuario){
    Denuncia *d;
    d = (Denuncia*)malloc(sizeof(Usuario));
    d -> code = gerarCodigoDenuncia();
    d -> postagem = postagem;
    d -> encerramento = encerramento;
    strcpy(d -> descricao,"Sem descricao");
    d -> endereco = end;
    d -> usuario = usuario;
    d -> status = NAFILA;

    return d;
}
FilaDenuncias * criarFilaDenuncias(){
    FilaDenuncias *f;
    f = (FilaDenuncias*)malloc(sizeof(FilaDenuncias));
    f -> inicio = NULL;
    f -> fim = NULL;
    f -> tamanho = 0;
    return f;
}
FilaUsuarios * criarFilaUsuarios(){
    FilaUsuarios *f;
    f = (FilaUsuarios*)malloc(sizeof(FilaUsuarios));
    f -> primeiro = NULL;
    f -> ultimo = NULL;
    f -> tamanho = 0;
    return f;
}


void pedirNomeUsuario(){
    printf("\n\tNome ... ");
}
void pedirSobreNomeUsuario(){
    printf("\n\tSobrenome ... ");
}
void pedirCpfUsuario(){
    printf("\n\tCpf ... ");
}
void pedirLoginUsuario(){
    printf("\n\tLogin ... ");
}
void pedirSenhaUsuario(){
    printf("\n\tSenha ... ");
}
void pedirTelefone(){
    printf("\n\tTelefone... ");
}
void pedirEmail(){
    printf("\n\tEmail... ");
}
void pedirEndereco(){
    printf("\n\tEndereco... ");
}
void pedirPais(){
    printf("\n\tPais... ");
}
void pedirEstado(){
    printf("\n\tEstado... ");
}
void pedirCidade(){
    printf("\n\tCidade... ");
}
void pedirBairro(){
    printf("\n\tBairro... ");
}
void pedirRua(){
    printf("\n\tRua... ");
}
void pedirNumero(){
    printf("\n\tNumero... ");
}
void pedirComplemento(){
    printf("\n\tComplemento... ");
}
void pedirCep(){
    printf("\n\tCep... ");
}
void pedirData(){
    printf("\n\tEntre ano mes e dia no formato AAAAMMDD... ");
}
void pedirAno(){
    printf("\n\tAno... ");
}
void pedirMes(){
    printf("\n\tMes... ");
}
void pedirDia(){
    printf("\n\tDia... ");
}
void pedirDescricao(){
    printf("\n\tAgora descreva o possivel foco de dengue ...\n");
}

void alterarUsuario(Usuario *u){
    exibirTelaNovoUsuario();
    Telefone *t1, *t2;
    exibirTelaNovoTelefone();
    t1 = criarTelefone(telefone1);
    exibirTelaNovoTelefone();
    t2 = criarTelefone(telefone2);
    Email *e;
    exibirTelaNovoEmail();
    e = criarEmail(email);
    exibirTelaNovoEndereco();
    Endereco *end;
    end = criarEndereco(pais, estado, cidade, bairro, rua, numero, complemento, cep);
    alterarUsuarioComParametros(u, nome, sobrenome, cpf, t1, t2, e, end, login, senha);
}
void alterarTelefone(Telefone *t, int num){
    if(num == 1){
        exibirTelaNovoTelefone();
        alterarTelefoneComParametros(t, telefone1);
        printf("\n\tTelefone 1 Alterado\n");
    }else if(num == 2){
        exibirTelaNovoTelefone();
        (t, telefone2);
        printf("\n\tTelefone 2 Alterado\n");
    }
    
}
void alterarEmail(Email *e){
    exibirTelaNovoEmail();
    alterarEmailComParametros(e, email);
    printf("\n\tEmail Alterado\n");
}
void alterarEndereco(Endereco *e){
    exibirTelaNovoEndereco();
    alterarEnderecoComParametros(e, pais, estado, cidade, bairro, rua, numero, complemento, cep);
    printf("\n\tEndereco alterado\n");
}
void alterarData(Data *d){
    exibirTelaNovaData();
    alterarDataComParametros(d, ano, mes, dia);
    printf("\n\tData alterado\n");

}


void alterarUsuarioComParametros(Usuario*u, char nome[30], char sobrenome[30], char cpf[15], Telefone *t1, Telefone *t2, Email *em, Endereco *end, char login[30], char senha[30]){
    strcpy(u -> nome, nome);
    strcpy(u -> sobrenome, sobrenome);
    strcpy(u -> cpf, cpf);
    u -> telefone1 = t1;
    u -> telefone2 = t2;
    u -> email = em;
    u -> endereco = end;
    strcpy(u -> login, login);
    strcpy(u -> senha, senha);
}
void alterarTelefoneComParametros(Telefone *t, char numero[15]){
    strcpy(t -> numero, numeroTelefone);
}
void alterarEmailComParametros(Email *e, char email[50]){
    strcpy(e -> email, email);
}
void alterarEnderecoComParametros(Endereco *e,char pais[30],char estado[30], char cidade[30], char bairro[50], char rua[50], int numero, char complemento[20], char cep[15]){
    strcpy(e -> pais, pais);
    strcpy(e -> estado, estado);
    strcpy(e -> cidade, cidade);
    strcpy(e -> bairro, bairro);
    strcpy(e -> rua, rua);
    e -> numero = numero;
    strcpy(e -> Complemento, complemento);
    strcpy(e -> cep, cep);
}
void alterarDataComParametros(Data *d, char ano[5], char mes[3], char dia[3]){
    strcpy(d -> ano, ano);
    strcpy(d -> mes, mes);
    strcpy(d -> dia, dia);
}
void alterarDenunciaComParametros(Denuncia *d, Data*dt1, Data*dt2, Endereco *e, Usuario *u){
    d -> postagem = dt1;
    d -> encerramento = dt2;
    d -> endereco = e;
    d -> usuario = u;
}



void alterarDataPostagem(Denuncia *d){
    exibirTelaNovaData();
    alterarDataComParametros(d -> postagem, ano, mes, dia);

}
void alterarDataEncerramento(Denuncia *d){
    exibirTelaNovaData();
    alterarDataComParametros(d -> encerramento, ano, mes, dia);
}
void alterarStatus(Denuncia *d){
    printf("\n\tEscolha uma opcao para alterar o status");
    printf("\n\t1 : NA FILA");
    printf("\n\t2 : EM ANALISE");
    printf("\n\t3 : ENCERRADA");
    int status;
    scanf("\n\t%d",&status);
    d -> status = status;
}


void alterarCodeUsuario(Usuario *u, int code){
    u -> cod = code;
}
void alterarCodTelefone(Telefone *t, int code){
    t -> cod = code;
}
void alterarCodEmail(Email *e, int code){
    e -> cod = code;
}
void alterarCodeEndereco(Endereco *e, int code){
    e -> cod = code;
}
void alterarCodeDenuncia(Denuncia *d, int code){
    d -> code = code;
}
void alterarCodeFilaDenuncias(FilaDenuncias *fd, int code){
    fd -> code = code;
}


void freeUsuario(Usuario *u){

    free(u -> telefone1 );
    free(u -> telefone2 );
    free(u -> endereco );
    free(u -> email );
    free(u);
}
void freeTelefone(Telefone *t){
    free(t);
}
void freeEmail(Email *e){
    free(e);
}
void freeEndereco(Endereco *e){
    free(e);
}
void freeFilaDenuncias(FilaDenuncias *fd){
    free(fd);
}
void freeEnd(Endereco *e){
    free(e);
}


void removerDenunciaDoInicioDaFila(Denuncia *);
void removerDenunciaDoMeioDaFila(Denuncia *);
void removerDenunciaDoFimDaFila(Denuncia *);



void exibirTelaNovoUsuario(){
    printf("\n\tNovo usuario... ");
    exibirCabecalho();
    pedirNomeUsuario();
    fflush(stdin);
    gets(nome);
    pedirSobreNomeUsuario();
    gets(sobrenome);
    pedirCpfUsuario();
    gets(cpf);
    pedirLoginUsuario();
    gets(login);
    pedirSenhaUsuario();
    gets(senha);
    exibirTelaNovoTelefone();
    exibirTelaNovoEmail();
    exibirTelaNovoEndereco();
}
void exibirTelaNovoTelefone(){
    fflush(stdin);
    pedirTelefone();
    gets(telefone1);
    pedirTelefone();
    gets(telefone2);
}
void exibirTelaNovoEmail(){
    fflush(stdin);
    pedirEmail();
    gets(email);
}
void exibirTelaNovoEndereco(){
    fflush(stdin);
    pedirEndereco();
    pedirPais();
    gets(pais);
    pedirEstado();
    gets(estado);
    pedirCidade();
    gets(cidade);
    pedirBairro();
    gets(bairro);
    pedirRua();
    gets(rua);
    pedirNumero();
    scanf("%d",&numero);
    fflush(stdin);
    pedirComplemento();
    gets(complemento);
    pedirCep();
    gets(cep);
}
void exibirTelanovaDenuncia(){
    Endereco *e;
    Data *data;
    exibirCabecalho();
    printf("\t\tNova Denuncia .\n");
    printf("\tQual o endereco do possivel foco de dengue...\n ");
    exibirTelaNovoEndereco();
    e = criarEndereco(pais, estado, cidade, bairro, rua, numero, complemento, cep);
    pedirDescricao();
    gets(descricao);
    exibirTelaNovaData();
    data = criarData(ano, mes, dia);
    Denuncia *d;
    d = criarDenuncia(data, e, usuario);
    inserirDenunciaNaFilaDenuncias(d);
    exibirTelaAtividades();
}
void exibirTelaNovaData(){
    fflush(stdin);
    pedirData();
    pedirAno();
    gets(ano);
    pedirMes();
    gets(mes);
    pedirDia();
    gets(dia);
}


void inserirDenunciaNaFilaDenuncias(Denuncia *d){
    
    if(FilaDenunciasVazia(filaDenuncias)){
        filaDenuncias -> inicio = d;
        d -> prox = NULL;
        d -> anterior = NULL;
        filaDenuncias -> fim = d;
        filaDenuncias -> tamanho ++;       
    }else if(FilaDenunciasCheia(filaDenuncias)){
        printf("\tFilaDenuncias cheia nao é possivel adicionar mais itens!\n");
    }else{

        if(filaDenuncias -> inicio -> prox == NULL && filaDenuncias -> inicio -> anterior == NULL){
            filaDenuncias -> inicio -> prox = d;
            filaDenuncias -> fim = d;
            d -> prox = NULL;
            d -> anterior = filaDenuncias -> inicio;
            filaDenuncias -> tamanho ++;
            //printf("Denuncia inserida na segunda posicao itens na FilaDenuncias = %d\n", filaDenuncias -> tamanho);

        }else{
            d -> anterior = filaDenuncias -> fim;
            filaDenuncias -> fim -> prox = d;
            filaDenuncias -> fim = d;
            d -> prox = NULL;
            filaDenuncias -> tamanho ++;
           // printf("Denuncia inserida no fim itens na FilaDenuncias = %d\n", filaDenuncias ->tamanho);
        }
    }
}
void inserirUsuarioNaFilaUsuario(Usuario *u){
    
    if(FilaUsuariosVazia(filaUsuarios)){
        filaUsuarios -> primeiro = u;
        u -> prox = NULL;
        u -> anterior = NULL;
        filaUsuarios -> ultimo = u;
        filaUsuarios -> tamanho ++;
        //printf("Primeira denuncia inserida itens na filaUsuarios = %d\n", filaUsuarios -> tamanho);
       
    }else if(FilaUsuariosCheia(filaUsuarios)){
        printf("\tFilaUsuarios cheia nao é possivel adicionar mais itens!\n");
    }else{

        if(filaUsuarios -> primeiro -> prox == NULL && filaUsuarios -> primeiro -> anterior == NULL){
            filaUsuarios -> primeiro -> prox = u;
            filaUsuarios -> ultimo = u;
            u -> prox = NULL;
            u -> anterior = filaUsuarios -> primeiro;
            filaUsuarios -> tamanho ++;
            //printf("Denuncia inserida na segunda posicao itens na filaUsuarios = %d\n", filaUsuarios -> tamanho);

        }else{
            u -> anterior = filaUsuarios -> ultimo;
            filaUsuarios -> ultimo -> prox = u;
            filaUsuarios -> ultimo = u;
            u -> prox = NULL;
            filaUsuarios -> tamanho ++;
            //printf("Denuncia inserida no fim itens na filaUsuarios = %d\n", filaUsuarios ->tamanho);
        }
    }
}


int FilaDenunciasVazia(FilaDenuncias *f){
    if(filaDenuncias == NULL || f -> tamanho == 0){
        printf("Fila vasia ou nula! itens na FilaDenuncias = %d \n",f -> tamanho);
        return 1;
    }
    return 0;
}
int FilaUsuariosVazia(FilaUsuarios *f){
    if(filaUsuarios == NULL || f -> tamanho == 0){
        printf("Verificando se a FilaDenuncias esta vazia! itens na FilaDenuncias = %d \n",f -> tamanho);
        return 1;
    }
    return 0;
}


int FilaDenunciasCheia(FilaDenuncias *f){
    if(f -> tamanho == 20){
        return 1;
    }
    return 0;
}
int FilaUsuariosCheia(FilaUsuarios *f){
    if(f -> tamanho == 100){
        return 1;
    }
    return 0;
}


Denuncia *pegarProximaDenuncia(FilaDenuncias *f){


    if(FilaDenunciasVazia(f)){
        printf("FilaDenuncias vazia nao foi possiver remover\n");
        return NULL;
    }else{
        Denuncia *d;
        d = f -> inicio;
        f ->inicio = f -> inicio -> prox;
        f -> tamanho--;
        return d; 
    }
}
Denuncia * pegarTodasAsDenuncias(Denuncia *d, FilaDenuncias *f){
	int i;
    Denuncia * denuncias;
    denuncias = (Denuncia*)malloc(f -> tamanho * sizeof(Denuncia));

    Denuncia *den;
    den = d;
    for(i = 0; i < f -> tamanho; i++){
        denuncias[i] = *den;
        den = den -> prox;  
    }
    return denuncias;
}
Usuario * pegarProximoUsuario(FilaUsuarios *f){
   return f -> primeiro;
}
Usuario * pegarTodosOsUsuarios(Usuario *u, FilaUsuarios *fu){
    int i;
    Usuario * usuarios;
    usuarios = (Usuario*)malloc(fu -> tamanho * sizeof(Denuncia));

    Usuario *user;
    user = u;
    for(i = 0; i < fu -> tamanho; i++){
        usuarios[i] = *user;
        user = user -> prox;  
    }
    return usuarios;
}

int verificarCodigoDenuncia(Denuncia *d, int cod){
    printf("\nCodigo\t%d\t%d",d -> code, cod);
    if (d -> code == cod )
    {
        return 1;
    }else{
        return 0;
    }  
}
int verificarCodigoUsuario(Usuario *u, int cod){
    printf("\nCodigo\t%d\t%d",u -> cod, cod);
    if (u -> cod == cod )
    {
        return 1;
    }else{
        return 0;
    }  
}

Denuncia * recuperarDenuncia(int cod){
    Denuncia *d;
    d = filaDenuncias -> inicio;
    do
    {
        if(verificarCodigoDenuncia(d, cod)){
            return d;
        }
        d = d -> prox;
    }while(d -> code != 0);
    printf("\n\tNao encontrado");
    return NULL;
}
Usuario * recuperarUsuario(int cod){
    Usuario *u;
    u = filaUsuarios -> primeiro;
    do
    {
        if(verificarCodigoUsuario(u, cod)){
            return u;
        }
        u = u -> prox;
    }while(u -> prox != NULL);
    printf("\n\tNao encontrado");
    return NULL;
}    
void esvasiarFilaDenuncias(){
    filaDenuncias -> tamanho = 0;
    filaDenuncias -> inicio = NULL;
    filaDenuncias -> fim = NULL;
    //free(filaDenuncias);

    printf("\n\tFilaDenuncias Esvasiada");
}
void esvasiarFilaUsuarios(){

    esvasiarFilaDenuncias();
    int i = 1;
    filaDenuncias -> inicio = NULL;
    filaDenuncias -> fim = NULL;
    filaDenuncias -> tamanho = 0;    
    printf("\n\tFilaUsuarios Esvasiada");
}
void removerProximaDenuncia(){

    if(FilaDenunciasVazia(filaDenuncias)){
        return;
    }
    removerDenuncia(filaDenuncias -> inicio);
}
void removerProximoUsuario(){
    if(FilaUsuariosVazia(filaUsuarios)){
        return;
    }
    Usuario *u;
    u = filaUsuarios -> primeiro;
    removerDenunciasDoUsuario(u);
    filaUsuarios -> primeiro = filaUsuarios -> primeiro -> prox;
    filaUsuarios -> tamanho--;
    imprimirUsuario(u);
}
void removerDenunciasDoUsuario(Usuario *u){
    if(FilaDenunciasVazia(filaDenuncias)){
        return;
    }
    Denuncia *d;
    d = filaDenuncias -> inicio;
    do
    {
        if(d -> usuario == u){
            removerDenuncia(d);
        }
        d = d -> prox;
    }while(d != NULL);
}
void removerDenuncia(Denuncia *d){
    
    if(filaDenuncias -> tamanho == 0){
        printf("\n\tFila Denuncias Vasia");
    }else if(filaDenuncias -> tamanho == 1){
        esvasiarFilaDenuncias();
    }else if(filaDenuncias -> tamanho == 2 && d == filaDenuncias -> inicio){
        removerDenunciaDoInicioDaFila(d);
        filaDenuncias -> inicio = filaDenuncias -> fim;
    }else if(filaDenuncias -> tamanho == 2 && d == filaDenuncias -> fim){
        removerDenunciaDoFimDaFila(d);
    
    }else if(d = filaDenuncias -> inicio){
        printf("\n\tDenuncia do inicio");
        removerDenunciaDoInicioDaFila(d);
    }else if(d = filaDenuncias -> fim){
        removerDenunciaDoFimDaFila(d);
    }else{
        removerDenunciaDoMeioDaFila(d);
    }
}
void removerDenunciaDoInicioDaFila(Denuncia *d){
    filaDenuncias -> inicio -> prox -> anterior = NULL;
    filaDenuncias -> inicio = filaDenuncias -> inicio -> prox;
    free(d); 
    filaDenuncias -> tamanho--;
}

void removerDenunciaDoMeioDaFila(Denuncia *d){
    d -> anterior -> prox = d -> prox;
    d -> prox -> anterior = d -> anterior;
    free(d); 
    filaDenuncias -> tamanho--;
}
void removerDenunciaDoFimDaFila(Denuncia *d){
    d -> anterior -> prox = NULL;
    free(d); 
    filaDenuncias -> tamanho--;
}

int recuperarStatusDenuncias(int status){
    if(FilaDenunciasVazia(filaDenuncias)){
        return 0;
    }
    int naFila = 0;
    int emAnalise = 0;
    int encerrado = 0;
    Denuncia *d;
    d = filaDenuncias -> inicio;
    do
    {
        if(d -> status == 0){
            naFila++;
        }else if(d -> status == 1){
            emAnalise++;
        }else if(d -> status == 2){
            encerrado++;
        }
        d = d -> prox;
    }while(d != NULL);

    switch (status)
    {
    case 0:
        return naFila;
        break;
    case 1:
        return emAnalise;
        break;
    case 2:
        return encerrado;
        break;
    default:
        return 0;
        break;
    }
}

void exibirVisaoGerral(){
    printf("\n**\tUsuarios cadastrados = %d ", filaUsuarios -> tamanho);
    printf("\n**\tDenuncias cadastradas = %d ", filaDenuncias -> tamanho);
    int denunciasNaFila = recuperarStatusDenuncias(0);
    int denunciasEmAnalise = recuperarStatusDenuncias(1);
    int denunciasEncerradas = recuperarStatusDenuncias(2);
    printf("\n**\tDenuncias na fila = %d ", denunciasNaFila);
    printf("\n**\tDenuncias em analise = %d ", denunciasEmAnalise);
    printf("\n**\tDenuncias emserradas = %d ", denunciasEncerradas);
}

int verificarDenunciaNulo(Denuncia *denuncia){
    if(usuario != NULL && usuario -> cod > 0){
        return 1;
    }else{
        return 0;
    }
    
}
int verificarUsuarioNulo(Usuario *u){
     if(denuncia != NULL && denuncia -> code > 0){
        return 1;
    }else{
        return 0;
    }
}


void imprimirUsuario(Usuario *u){
    printf("\n***********************************************************************************");
    if(verificarUsuarioNulo(u)){
        printf("\n\tUsuario nao cadastrado");
    }
    printf("\n*\tNome = %s ", u -> nome);
    printf("Sobrenome = %s ", u -> sobrenome);
    printf("Cpf = %s ", u -> cpf);
    printf("\n*\tLogin = %s ", u -> login);
    printf("Senha = %s ", u -> senha);
    imprimirTelefone(u -> telefone1);
    imprimirTelefone(u -> telefone2);
    imprimirEmail(u -> email);
    printf("\n*\t\tEndereco do usuario");
    imprimirEndereco(u -> endereco);
    printf("\n***********************************************************************************\n");    
}
void imprimirTelefone(Telefone *t){
    printf("\n*\tTelefone %s ",t -> numero);
}
void imprimirEmail(Email *e){
    printf("\n*\tEmail %s",e -> email);
}
void imprimirEndereco(Endereco *end){
    printf("\n*\tPais = %s ", end -> pais );
    printf("\n*\tEstado = %s ", end -> estado );
    printf("\n*\tCidade = %s ", end -> cidade );
    printf("\n*\tBairro = %s ", end -> bairro );
    printf("\n*\tRua = %s ", end -> rua );
    printf("\n*\tNumero = %d ", end -> numero );
    printf("\n*\tComplemento = %s ", end -> Complemento );
    printf("\n*\tCep = %s ", end -> cep );
}
void imprimirData(Data *d){
    printf("\tData ");
    printf("%s", d -> ano);
    printf(" %s ", d -> mes);
    printf("%s", d -> dia);
}
void imprimirStatus(Denuncia *d){
    switch (d -> status)
    {
    case 0:
        printf("NA FILA");
        break;
    case 1:
        printf("EM ANALISE");
        break;
    case 2:
        printf("ENCERRADA");
        break;
    
    default:
        printf("NAO ENCONTRADO");
        break;
    }
}
void imprimirDenuncia(Denuncia *d){
    printf("\n******************************************************************************************************************");
    printf("\n*\tCodigo = %d ", d -> code); 
    printf("\n*\tStatus = ");
    imprimirStatus(d);
    printf("\n*\tData da postagem  = ");
    imprimirData(d -> postagem);
    printf("\n*\tDescricao = %s ",d -> descricao);
    printf("\n*\tEndereco da denuncia.");
    imprimirEndereco(d -> endereco);
    printf("\n*\tUsuario que fez a denuncia: ");
    printf("\n*\tNome = %s %s Contato = %s %s\n", d -> usuario -> nome, d -> usuario -> sobrenome, d -> usuario -> telefone1 -> numero, d -> usuario -> telefone2 -> numero );
    printf("\n******************************************************************************************************************");
}



void imprimirTodasAsDenuncias(Denuncia *d){
    
    imprimirDenuncia(d);

    if(d -> prox != NULL){
        imprimirTodasAsDenuncias(d ->prox);
    }
}
void imprimirTodasAsDenunciasUsuario(Denuncia *d, Usuario *u){
    if(d -> usuario -> cod == u -> cod){
        printf("\n\t Codigos = %d %d ",d -> usuario -> cod, u -> cod);
        imprimirDenuncia(d);
    }
    printf("\n\t Codigos fora = %d %d ",d -> usuario -> cod, u -> cod);
    if(d -> prox != NULL){
        imprimirTodasAsDenunciasUsuario(d ->prox, u);
    }
}
void imprimirDenunciaComFiltro(Denuncia *d, int filtro, char referencia[50]){

    if(FilaDenunciasVazia(filaDenuncias)){
        printf("Nao foi possivel aplicar o filtro porque a FilaDenuncias esta vazia.\n");
    }else{

        switch (filtro){

        case 1:
            if(strncmp(d -> endereco -> pais , referencia, 30) == 0){
                imprimirDenuncia(d);
            }
            break;
        case 2:
            if(strncmp(d -> endereco -> estado , referencia, 30) == 0){
                imprimirDenuncia(d);
            }
            break;
        case 3:
            if(strncmp(d -> endereco -> cidade, referencia, 30) == 0){
                imprimirDenuncia(d);
            }
            break;
        case 4:
            if(strncmp(d -> endereco -> bairro, referencia, 50) == 0){
                imprimirDenuncia(d);
            }
            break;
        case 5:
            if(strncmp(d -> endereco -> rua, referencia, 50) == 0){
                imprimirDenuncia(d);
            }
            break;
        default:
            break;
        }

    }

    
}
void imprimirTodasAsDenunciasComFiltro(Denuncia *d, int filtro, char referencia[50]){
    
    imprimirDenunciaComFiltro(d, filtro ,referencia);

    if(d -> prox != NULL){
        imprimirTodasAsDenunciasComFiltro(d ->prox, filtro ,referencia);
    }
}
void imprimirFilaDenuncias(){
    if(filaDenuncias == NULL || FilaDenunciasVazia(filaDenuncias)){
        printf("\n\tFila Nula Ou vasia");
        return;
    }else{
        imprimirTodasAsDenuncias(filaDenuncias -> inicio);
    }
}


void imprimirTodosOsUsuarios(Usuario *u){
    imprimirUsuario(u);

    if(u -> prox != NULL){
        imprimirTodosOsUsuarios(u ->prox);
    }
}

void imprimirUsuarioComFiltro(Usuario *u, int filtro, char referencia[50], int cod){
    if(FilaUsuariosVazia(filaUsuarios)){
        printf("Nao foi possivel aplicar o filtro porque a FilaUsuario esta vazia.\n");
        return;
    }

    switch (filtro){

    case 1:
        printf("\n\tComparando nome");
        printf("\n\t Nome usuario %s ", u -> nome);
        printf("\n\t Referencia %s ", referencia);
        printf("%d",compararNome(u, referencia));
        if(strncmp(u -> nome , referencia,30) == 0){
            imprimirUsuario(u);
        }
        break;
    case 2:
        printf("\n\tComparando sobrenome");
        if(strncmp(u -> sobrenome, referencia, 30) == 0){
            imprimirUsuario(u);
        }
        break;
    case 3:
        printf("\n\tComparando Cpf");
        if(strncmp(u -> cpf, referencia, 15) == 0){
            imprimirUsuario(u);
        }
        break;
    case 4:
        printf("\n\tComparando Codigo");
        if(u -> cod == cod){
        	Usuario *u = recuperarUsuario(cod);
           imprimirUsuario(u);
        }
        break;
    case 5:
        exibirTelaConsultarUsuario();
        break;
    default:
        printf("\n\tUsuario nao encontrado");
        exibirTelaConsultarUsuario();
        break;
    }
}
void imprimirTodosOsUsuariosComFiltro(Usuario *u, int filtro, char referencia[50], int codigo){
    imprimirUsuarioComFiltro(u, filtro ,referencia, codigo);

    if(u -> prox != NULL){
        imprimirTodosOsUsuariosComFiltro(u ->prox, filtro ,referencia, codigo);
    }
}
void imprimirFilaUsuarios(){
    if(FilaUsuariosVazia(filaUsuarios)){
        printf("\n\tFila vasia");
        return;
    }else{
        imprimirTodosOsUsuarios(filaUsuarios -> primeiro);
    }
}


void exibirCabecalho(){
    printf("\n*\t_______________________________________________________________\n");
    printf("\n*\t\t XXXXXXXX Projeto zero Dengue XXXXXXXXX\n");
    printf("\n*\t_______________________________________________________________");
    printf("\n*\t\t  Bem vindo ao sistema zero dengue \n\n");
}
void exibirTelaInicial(){
    usuarioLogado = NULL;
    int opcao = exibirTelaOpcoesTelaInicial();
    
    switch (opcao){
    case 1:
        exibirTelaLogin();
        break;
    
    case 2:
        exibirTelaCadastro();
        break;
    default:
        break;
    }
}

void exibirTelaLogin(){

    char login[30];
    char senha[30];

    exibirCabecalho();
    pedirLoginUsuario();
    fflush(stdin);
    gets(login);
    pedirSenhaUsuario();
    gets(senha);   

    if(autenticarUsuario(filaUsuarios -> primeiro ,login, senha)){
        exibirTelaAtividades();
        return;
    }
    printf("\tUsuario nao cadastrado.\n");
    exibirTelaInicial();
}
void exibirTelaCadastro(){
    
    exibirTelaNovoUsuario();
    Telefone *tel1 = criarTelefone(telefone1);
    Telefone *tel2 = criarTelefone(telefone2);
    Endereco *end1 = criarEndereco(pais, estado, cidade, bairro, rua, numero, complemento, cep );
    Email *email1 = criarEmail(email);
    usuario = criarUsuario(nome, sobrenome, cpf, tel1, tel2, email1, end1, login, senha);
    if(usuario != NULL){
           printf("\t\tUsuario cadastrado com sucesso!\n");
    }else{
           printf("\t\tNao foi possivel concluir o cadastrado!\n");
    }
    exibirTelaInicial();
}
void exibirTelaAlterarUsuario(){
    exibirCabecalho();
    printf("\t\t  Opcoes\n\n");
    printf("\t\t  1 = Alterar telefone1.\n");
    printf("\t\t  2 = Alterar telefone2.\n");
    printf("\t\t  3 = Alterar Email.\n");
    printf("\t\t  4 = Alterar Endereco.\n");
    printf("\t\t  5 = Voltar.\n");
    printf("\t\t  Digite 1 2 3 ou 4.\n");
    int opcao = 0;
    scanf("%d",&opcao);

    switch (opcao){
        case 1:
            alterarTelefone(usuario ->telefone1, 1);
            exibirTelaAlterarUsuario();
            break;
        case 2:
            alterarTelefone(usuario ->telefone2, 2);
            exibirTelaAlterarUsuario();
            break;
        case 3:
            alterarEmail(usuario -> email);
            exibirTelaAlterarUsuario();
            break;
        case 4:
            alterarEndereco(usuario -> endereco);
            exibirTelaAlterarUsuario();
            break;
        case 5:
            exibirTelaAtividades();
        break;
        default:
            exibirTelaAtividades();
            break;
        }
}
void exibirTelaAlterarDenuncia(){
    
    Denuncia *d;
    printf("\n\tDigite o codigo da denuncia a ser alterada");
    int codigo;
    scanf("%d", &codigo);
    if(codigo > filaDenuncias ->tamanho){
        printf("\n\tDenuncia nao encontrada");
        exibirTelaGerenciarDenuncias();
    }
    d = recuperarDenuncia(codigo);
    imprimirDenuncia(d);
    int opcao = exibirTelaOpcoesAlterarDenuncia();
    
    switch (opcao)
    {
    case 1:
        alterarDataPostagem(d);
        exibirTelaGerenciarDenuncias();
        break;
    case 2:
        alterarDataEncerramento(d);
        exibirTelaGerenciarDenuncias();
        break;
    case 3:
        alterarStatus(d);
        exibirTelaGerenciarDenuncias();
        break;
    case 4:
        
        exibirTelaGerenciarDenuncias();
        break;
    
    default:
        exibirTelaGerenciarDenuncias();
        break;
    }
}
void exibirTelaAtividades(){

    exibirCabecalho();
    int opcao = exibirOpcoesTelaAtividades();
    switch (opcao){
        case 1:
            exibirTelaGerenciarDenuncias();
            break;
        case 2:
            exibirTelaGerenciarUsuarios();
            break;
        case 3:
            exibirTelaGerenciarFilaDenuncias();
            break;
        case 4:
            exibirTelaGerenciarFilaUsuarios();
            break; 
        case 5:
            exibirTelaInicial();
        break;      
        default:
            exibirTelaInicial();
            break;
        }
}
void exibirTelaConsultarDenuncias(){

    exibirCabecalho();
    int opcao = exibirTelaOpcoesConsultarDenuncias();
    switch (opcao)
    {
    case 1:
        imprimirFilaDenuncias(filaDenuncias);
        exibirTelaConsultarDenuncias();
        break;
    case 2:
        filtrarDenuncias();
        exibirTelaConsultarDenuncias();
        break;
    case 3:
        imprimirTodasAsDenunciasUsuario(filaDenuncias -> inicio, usuarioLogado);
        exibirTelaConsultarDenuncias();
        break;
    case 4:
        exibirTelaAtividades();
    break;
    default:
        exibirTelaInicial();
        break;
    }

}
void exibirTelaConsultarUsuario(){
    int opcao = exibirTelaOpcoesConsultarUsuario();
    switch (opcao)
    {
    case 1:
        imprimirTodosOsUsuarios(filaUsuarios -> primeiro);
        exibirTelaConsultarUsuario();
        break;
    case 2:
        filtrarUsuarios();
        exibirTelaConsultarUsuario();
        break;
    case 3:
        exibirTelaAtividades();
        break;
    default:
        exibirTelaInicial();
        break;
    }
}
void exibirTelaGerenciarFilaDenuncias(){
    int opcao = exibirTelaOpcoesGerenciarFilaDenuncias();
    switch(opcao){
    case 1:
        esvasiarFilaDenuncias();
        exibirTelaAtividades();
        break;
    case 2:
        removerProximaDenuncia();
        exibirTelaGerenciarFilaDenuncias();
        break;
    case 3:
        exibirVisaoGerral();
        exibirTelaAtividades();
        break;
    default: 
        exibirTelaAtividades();
        break;   
    }

}
void exibirTelaGerenciarFilaUsuarios(){
    int opcao = exibirTelaOpcoesGerenciarfilaUsuarios();
    switch(opcao){
    case 1:
        esvasiarFilaUsuarios();
        exibirTelaAtividades();
        break;
    case 2:
        removerProximoUsuario();
        exibirTelaGerenciarFilaUsuarios();
        break;
    case 3:
        exibirVisaoGerral();
        exibirTelaAtividades();
        break;
    default: 
        exibirTelaAtividades();
        break;   
    }

}

void exibirTelaGerenciarUsuarios(){
    int opcao = exibirTelaOpcoesGerenciarUsuarios();

    switch (opcao)
    {
    case 1:
        exibirTelaConsultarUsuario();
        break;
    
    case 2:
        exibirTelaAlterarUsuario();
        break;
    
    case 3:
        exibirTelaAtividades();
        break;
    
    default:
        break;
    }
}
void exibirTelaGerenciarDenuncias(){
    int opcao = exibirTelaOpcoesGerenciarDenuncia();
    switch (opcao)
    {
    case 1:
        exibirTelaConsultarDenuncias();
        break;
    case 2:
        exibirTelaAlterarDenuncia();
        break;
    case 3:
        exibirTelanovaDenuncia();
        break;
    case 4:
        exibirTelaAtividades();
        break;
    
    default:
        exibirTelaAtividades();
        break;
    }
}


int exibirOpcoesTelaAtividades(){
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Denuncias.\n");
    printf("\t\t  2 = Usuarios.\n");
    printf("\t\t  3 = Gerenciar fila Denuncias.\n");
    printf("\t\t  4 = Gerenciar fila Usuarios.\n");
    printf("\t\t  5 = Sair.\n");
    printf("\t\t  Digite 1 2 3 4 ou 5.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesConsultarDenuncias(){
    printf("n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Ver todas as denuncias.\n");
    printf("\t\t  2 = Filtrar denuncias.\n");
    printf("\t\t  3 = Ver apenas minhas denuncias.\n");
    printf("\t\t  4 = Voltar.\n");
    printf("\t\t  Digite 1 2 3 ou 4.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesAlterarDenuncia(){
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Alterar data postagem.\n");
    printf("\t\t  2 = Alterar data encerramento.\n");
    printf("\t\t  3 = Alterar Status.\n");
    printf("\t\t  4 = Remover denuncia.\n");
    printf("\t\t  Digite 1 2 3 ou 4.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesFiltrarDenuncias(){
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Por pais.\n");
    printf("\t\t  2 = Por Estado.\n");
    printf("\t\t  3 = Por cidade.\n");
    printf("\t\t  4 = Por bairro.\n");
    printf("\t\t  5 = Por rua.\n");
    printf("\t\t  Digite 1 2 3 4 ou 5.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    fflush(stdin);
    return opcao;
}
int exibirTelaOpcoesFiltrarUsuarios(){
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Por Nome.\n");
    printf("\t\t  2 = Por Sorenome.\n");
    printf("\t\t  3 = Por Cpf.\n");
    printf("\t\t  4 = Por Codigo.\n");
    printf("\t\t  5 = Voltar.\n");
    printf("\t\t  Digite 1 2 3 4 ou 5.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesGerenciarUsuarios(){
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Consultar usuarios.\n");
    printf("\t\t  2 = Alterar usuario.\n");
    printf("\t\t  3 = Voltar.\n");
    printf("\t\t  Digite 1 2 ou 3.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesGerenciarDenuncia(){
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Consultar denuncias.\n");
    printf("\t\t  2 = Alterar denunias.\n");
    printf("\t\t  3 = Nova denuncia.\n");
    printf("\t\t  4 = Voltar.\n");
    printf("\t\t  Digite 1 2 3 ou 4.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesTelaInicial(){
    exibirCabecalho();
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Fazer login.\n");
    printf("\t\t  2 = Fazer Cadastro.\n");
    printf("\t\t  3 = Encerrar sessao.\n");
    printf("\t\t  Digite 1 2 ou 3.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesConsultarUsuario(){
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Ver todas os usuarios.\n");
    printf("\t\t  2 = Filtrar usuarios.\n");
    printf("\t\t  3 = Voltar.\n");
    printf("\t\t  Digite 1 2 ou 3 .\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesGerenciarFilaDenuncias(){
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Esvasiar fila.\n");
    printf("\t\t  2 = Remover proxima denuncia.\n");
    printf("\t\t  3 = Visao geral.\n");
    printf("\t\t  4 = Voltar.\n");
    printf("\t\t  Digite 1 2 3 ou 4.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}
int exibirTelaOpcoesGerenciarfilaUsuarios(){
    printf("\n\t\t  Opcoes\n\n");
    printf("\t\t  1 = Esvasiar fila.\n");
    printf("\t\t  2 = Remover proximo usuario.\n");
    printf("\t\t  3 = Visao geral.\n");
    printf("\t\t  4 = Voltar.\n");
    printf("\t\t  Digite 1 2 3 ou 4.\n");
    int opcao = 0;
    scanf("%d",&opcao);
    return opcao;
}

int autenticarUsuario(Usuario *u, char login[30], char senha[30]){
    
    int loginIgual = compararLogin(u, login);
    int senhaIgual = compararSenha(u, senha);

    if(loginIgual == 0 && senhaIgual == 0){
        usuarioLogado = u;    
        return 1;
    }else if(u -> prox != NULL){

        autenticarUsuario(u -> prox, login, senha); 
    }else{

        return 0;
    }
}
void filtrarDenuncias(){

    int filtro = exibirTelaOpcoesFiltrarDenuncias();
    char referencia[50];
    fflush(stdin);
    switch (filtro)
    {
    case 1:
        printf("\tDigite o nome do pais = ");
        gets(referencia);
        imprimirTodasAsDenunciasComFiltro(filaDenuncias -> inicio, 1, referencia );
        break;
    
    case 2:
        printf("\tDigite o nome do estado = ");
        gets(referencia);
        imprimirTodasAsDenunciasComFiltro(filaDenuncias -> inicio, 2, referencia );
        break;
    
    case 3:
        printf("\tDigite o nome da cidade = ");
        gets(referencia);
        imprimirTodasAsDenunciasComFiltro(filaDenuncias -> inicio, 3, referencia );
        break;
    
    case 4:
        printf("\tDigite o nome do bairro = ");
        gets(referencia);
        imprimirTodasAsDenunciasComFiltro(filaDenuncias -> inicio, 4, referencia );
        break;
    
    case 5:
        printf("\tDigite o nome da rua = ");
        gets(referencia);
        imprimirTodasAsDenunciasComFiltro(filaDenuncias -> inicio, 5, referencia );
        break;
    
    default:
        break;
    }
    
}
void filtrarUsuarios(){
    char referencia[50];
    int cod;
    int opcao = exibirTelaOpcoesFiltrarUsuarios();
    fflush(stdin);
    switch (opcao)
    {
    case 1:
        printf("\tDigite o nome do usuario = ");
        gets(referencia);
        imprimirTodosOsUsuariosComFiltro(filaUsuarios -> primeiro, 1, referencia, 0);
        break;
    
    case 2:
        printf("\tDigite o Sobrenome do usuario = ");
        gets(referencia);
        imprimirTodosOsUsuariosComFiltro(filaUsuarios -> primeiro, 2, referencia, 0);
        break;
    
    case 3:
        printf("\tDigite o Cpf do usuario = ");
        gets(referencia);
        imprimirTodosOsUsuariosComFiltro(filaUsuarios -> primeiro, 3, referencia, 0);
        break;
    
    case 4:
        printf("\tDigite o codigo do usuario = ");
        scanf("%i",&cod);
        printf("\n\t%d", cod);
        imprimirTodosOsUsuariosComFiltro(filaUsuarios -> primeiro, 4, referencia, cod);
        break;
    
    case 5:
        exibirTelaConsultarUsuario();
        break;
    
    default:
        break;
    }
}


int main(){

    filaDenuncias = NULL;
    filaUsuarios = NULL;
    codigoUsuario = 0;
    codigoDenuncia = 0;
    usuariosCadastrados = 0;
    usuario = NULL;
    filaDenuncias = criarFilaDenuncias();
    filaUsuarios = criarFilaUsuarios();
    teste();
    exibirTelaInicial();
    //exibirVisaoGerral(); 
    //imprimirTodasAsDenuncias(filaDenuncias -> inicio);
/*
    printf("\n\tNome do usuario %s ",filaUsuarios -> primeiro -> nome);
    char nome[30];
    gets(nome);
    int igual = strncmp(filaUsuarios -> primeiro -> nome, nome, 30);
    printf("\n\t%d", igual);
    printf("\n\t%d", compararNome(filaUsuarios -> primeiro, "jhonatan soares"));
    fflush(stdin);

    char n[30];
    char s[30];

    printf("\n\tnome = ");
    gets(n);
    printf("\n\tsobrenome = ");
    gets(s);

    printf("\n\tdigitou Nome %s ", n);
    printf("\n\tdigitou Sobre nome %s ", s);

    printf("\n\t n digitado lengh %d ",strlen(n));
    printf("\n\t s digitado lengh %d ",strlen(s));

    char nm[30] = {"jhonatan soares"};
    char sn[30] = {"jhonatan soares da silva"};

    printf("\n\t char nm lengh %d ",strlen(nm));
    printf("\n\t cha sn lengh %d ",strlen(sn));

    int c1 = strncmp(n, nm, 30);
    int c2 = strncmp(s, sn, 30);

    printf("\n\tC1 = %d", c1);
    printf("\n\tC2 = %d", c2);


*/

    return 0;
}

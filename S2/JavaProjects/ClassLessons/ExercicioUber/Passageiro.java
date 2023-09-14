package ExercicioUber;

public class Passageiro {
    
    private String nome;
    private String logradouro;
    private int cep;
    private int numCasa;
    private String cidade;
    private String uf;
    private String bairro;
    private String cpf;

    public void setNome(String nome){
        this.nome = nome;
    }
    public String getNome(){
        return this.nome;
    }

    public void setLogradouro(String logradouro){
        this.logradouro = logradouro;
    }
    public String getLogradouro(){
        return this.logradouro;
    }

    public void setCep(int cep){
        this.cep = cep;
    }
    public int getCep(){
        return this.cep;
    }
    
    public void setNumCasa(int num){
        this.numCasa = num;
    }
    public int getNumCasa(){
        return this.numCasa;
    }

    public void setCidade(String cidade){
        this.cidade = cidade;
    }
    public String getCidade(){
        return this.cidade;
    }

    public void setUf(String uf){
        this.uf = uf;
    }
    public String getUf(){
        return this.uf;
    }

    public void setBairro(String bairro){
        this.bairro = bairro;
    }
    public String getBairro(){
        return this.bairro;
    }

    public void setCpf(String cpf){
        this.cpf = cpf;
    }
    public String getCpf(){
        return this.cpf;
    }

}

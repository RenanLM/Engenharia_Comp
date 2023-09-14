package ExercicioUber;

import java.util.ArrayList;
import java.util.List;

public class Veiculo{
	
	private String marca;
	private String modelo;
	private int anoDeFabricacao;
	private int numMaxPassageiros;
	private List<Passageiro> passageiros;

    public Veiculo() {
        passageiros = new ArrayList<>();
    }
	
	public void setMarca(String marca){
		this.marca = marca;
	}
	public String getMarca(){
		return this.marca;
	}
	
	public void setModelo(String modelo){
		this.modelo = modelo;
	}
	public String getModelo(){
		return this.modelo;
	}
	
	public void setAno(int ano){
		this.anoDeFabricacao = ano;
	}
	public int getAno(){
		return this.anoDeFabricacao;
	}
	
	public void setNumMaxPassageiros(int numMax){
		this.numMaxPassageiros = numMax;
	}
	public int getNumMax(){
		return this.numMaxPassageiros;
	}

	public boolean embarcarPassageiro(Passageiro passageiro) {
        if (passageiros.size() < numMaxPassageiros) {
            passageiros.add(passageiro);
            System.out.println(passageiro.getNome() + " embarcou no veículo.");
            return true;
        } else {
            System.out.println("Não há capacidade para embarcar " + passageiro.getNome() + ".");
            return false;
        }
    }

    public boolean desembarcarPassageiro(Passageiro passageiro) {
        if (passageiros.contains(passageiro)) {
            passageiros.remove(passageiro);
            System.out.println(passageiro.getNome() + " desembarcou do veículo.");
            return true;
        } else {
            System.out.println(passageiro.getNome() + " não está a bordo do veículo.");
            return false;
        }
    }

	public void listarPassageirosEmbarcados() {
        System.out.println("Passageiros a bordo do veículo:");
        for (int i = 0; i < passageiros.size(); i++) {
            Passageiro passageiro = passageiros.get(i);
            System.out.println("Nome: " + passageiro.getNome());
            System.out.println("CPF: " + passageiro.getCpf());
            System.out.println("Logradouro: " + passageiro.getLogradouro());
            System.out.println("CEP: " + passageiro.getCep());
            System.out.println("Número da Casa: " + passageiro.getNumCasa());
            System.out.println("Cidade: " + passageiro.getCidade());
            System.out.println("UF: " + passageiro.getUf());
            System.out.println("Bairro: " + passageiro.getBairro());
            System.out.println();
        }
    }
	
}
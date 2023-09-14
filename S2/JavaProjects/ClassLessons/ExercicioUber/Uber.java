package ExercicioUber;

public class Uber {

    public static void main(String[] args) {
        // Criar um veículo
        Veiculo veiculo = new Veiculo();
        veiculo.setMarca("Volkswagen");
        veiculo.setModelo("UP!");
        veiculo.setAno(2017);
        veiculo.setNumMaxPassageiros(4);

        Passageiro passageiro1 = new Passageiro();
        passageiro1.setNome("Alice");
        passageiro1.setCpf("123.456.789-01");
        passageiro1.setLogradouro("Rua 10");
        passageiro1.setCep(60546310);
        passageiro1.setNumCasa(101);
        passageiro1.setCidade("Fortaleza");
        passageiro1.setUf("CE");
        passageiro1.setBairro("Bom Jardim");

        Passageiro passageiro2 = new Passageiro();
        passageiro2.setNome("Mário");
        passageiro2.setCpf("987.654.321-09");
        passageiro2.setLogradouro("Rua Canguru");
        passageiro2.setCep(60870070);
        passageiro2.setNumCasa(202);
        passageiro2.setCidade("Fortaleza");
        passageiro2.setUf("CE");
        passageiro2.setBairro("Conjunto Palmeiras");

        veiculo.embarcarPassageiro(passageiro1);
        veiculo.embarcarPassageiro(passageiro2);

        veiculo.listarPassageirosEmbarcados();

        veiculo.desembarcarPassageiro(passageiro1);

        veiculo.listarPassageirosEmbarcados();
    }
}

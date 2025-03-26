class CartaPais:
    def __init__(self, nome, populacao, area, pib, pontos_turisticos):
        self.nome = nome
        self.populacao = populacao
        self.area = area
        self.pib = pib
        self.pontos_turisticos = pontos_turisticos
        self.densidade_demografica = populacao / area if area > 0 else 0

def criar_cartas():
    cartas = [
        CartaPais("Brasil", 213993437, 8515767.049, 1.445, 21),
        CartaPais("Estados Unidos", 331002651, 9833517.0, 20.94, 50),
        CartaPais("Japão", 126476461, 377975.0, 5.06, 35),
        CartaPais("Alemanha", 83783942, 357022.0, 3.85, 28),
        CartaPais("Austrália", 25499884, 7692024.0, 1.39, 18)
    ]
    return cartas

def exibir_carta(carta):
    print(f"\nPaís: {carta.nome}")
    print(f"1. População: {carta.populacao:,} habitantes")
    print(f"2. Área: {carta.area:,.2f} km²")
    print(f"3. PIB: US${carta.pib:,.2f} trilhões")
    print(f"4. Pontos Turísticos: {carta.pontos_turisticos}")
    print(f"5. Densidade Demográfica: {carta.densidade_demografica:,.2f} hab/km²")

def comparar_cartas(carta1, carta2, atributo):
    if atributo == 1:  # População
        valor1, valor2 = carta1.populacao, carta2.populacao
    elif atributo == 2:  # Área
        valor1, valor2 = carta1.area, carta2.area
    elif atributo == 3:  # PIB
        valor1, valor2 = carta1.pib, carta2.pib
    elif atributo == 4:  # Pontos Turísticos
        valor1, valor2 = carta1.pontos_turisticos, carta2.pontos_turisticos
    elif atributo == 5:  # Densidade Demográfica
        valor1, valor2 = carta1.densidade_demografica, carta2.densidade_demografica
    
    # Determina o vencedor com regra especial para densidade
    if atributo == 5:  # Para densidade, menor valor vence
        if valor1 < valor2:
            return carta1
        elif valor2 < valor1:
            return carta2
        else:
            return None  # Empate
    else:  # Para outros atributos, maior valor vence
        if valor1 > valor2:
            return carta1
        elif valor2 > valor1:
            return carta2
        else:
            return None  # Empate

def exibir_resultado(carta1, carta2, atributo, vencedor):
    atributos_nomes = {
        1: "População",
        2: "Área",
        3: "PIB",
        4: "Pontos Turísticos",
        5: "Densidade Demográfica"
    }
    
    print("\n=== RESULTADO DA COMPARAÇÃO ===")
    print(f"País 1: {carta1.nome} vs País 2: {carta2.nome}")
    print(f"Atributo comparado: {atributos_nomes[atributo]}")
    
    if atributo == 1:
        print(f"Valores: {carta1.populacao:,} vs {carta2.populacao:,}")
    elif atributo == 2:
        print(f"Valores: {carta1.area:,.2f} vs {carta2.area:,.2f}")
    elif atributo == 3:
        print(f"Valores: {carta1.pib:,.2f} vs {carta2.pib:,.2f}")
    elif atributo == 4:
        print(f"Valores: {carta1.pontos_turisticos} vs {carta2.pontos_turisticos}")
    elif atributo == 5:
        print(f"Valores: {carta1.densidade_demografica:,.2f} vs {carta2.densidade_demografica:,.2f}")
    
    if vencedor:
        print(f"\nVencedor: {vencedor.nome}!")
    else:
        print("\nEmpate!")

def main():
    cartas = criar_cartas()
    
    print("=== SUPER TRUNFO - PAÍSES ===")
    print("Escolha duas cartas para comparar:")
    
    for i, carta in enumerate(cartas, 1):
        print(f"{i}. {carta.nome}")
    
    # Selecionar cartas
    while True:
        try:
            escolha1 = int(input("\nDigite o número da primeira carta: ")) - 1
            escolha2 = int(input("Digite o número da segunda carta: ")) - 1
            
            if 0 <= escolha1 < len(cartas) and 0 <= escolha2 < len(cartas) and escolha1 != escolha2:
                break
            else:
                print("Escolha inválida. Por favor, selecione números de cartas diferentes e dentro do intervalo.")
        except ValueError:
            print("Por favor, digite um número válido.")
    
    carta1 = cartas[escolha1]
    carta2 = cartas[escolha2]
    
    # Exibir cartas selecionadas
    print("\n=== CARTAS SELECIONADAS ===")
    exibir_carta(carta1)
    exibir_carta(carta2)
    
    # Menu de atributos
    while True:
        print("\n=== MENU DE ATRIBUTOS ===")
        print("1. População")
        print("2. Área")
        print("3. PIB")
        print("4. Pontos Turísticos")
        print("5. Densidade Demográfica")
        print("0. Sair")
        
        try:
            opcao = int(input("\nEscolha o atributo para comparar (1-5) ou 0 para sair: "))
            
            if opcao == 0:
                print("Obrigado por jogar!")
                return
            elif 1 <= opcao <= 5:
                vencedor = comparar_cartas(carta1, carta2, opcao)
                exibir_resultado(carta1, carta2, opcao, vencedor)
                
                # Perguntar se quer comparar novamente
                while True:
                    continuar = input("\nDeseja comparar com outro atributo? (s/n): ").lower()
                    if continuar in ['s', 'n']:
                        break
                    print("Por favor, digite 's' para sim ou 'n' para não.")
                
                if continuar == 'n':
                    print("Obrigado por jogar!")
                    return
            else:
                print("Opção inválida. Por favor, escolha um número entre 1 e 5.")
        except ValueError:
            print("Por favor, digite um número válido.")

if __name__ == "__main__":
    main()

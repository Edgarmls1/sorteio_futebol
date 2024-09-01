import acoes_partida as ap

while True:
    ap.menu()
    opcao = int(input(''))

    match opcao:
        case 1:
            ap.partida()
        case 2:
            ap.mostrar_historico()
        case 3:
            ap.salvar()
        case 4:
            ap.partidas_anteriores()
        case 5:
            break
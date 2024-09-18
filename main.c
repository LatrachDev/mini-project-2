#include <stdio.h>
#include <string.h>

int main()
{
    char titre[100][20], auteur[100][20];
    int choix, nombre = 0, quantite[100], new_quantity;
    float prix[100];

    do
    {
        printf("\nMenu Principal :\n");
        printf("1. Ajouter un livre au stock\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Mettre a jour la quantite d'un livre\n");
        printf("4. Supprimer un livre du stock.\n");
        printf("5. Afficher le nombre total de livres en stock.\n");
        printf("6. Quitter.\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                if (nombre >= 100)
                {
                    printf("Nombre maximum de livres atteint.\n");
                    break;
                }

                printf("Entrez le titre du livre : ");
                scanf("%s", titre[nombre]);

                printf("Entrez l'auteur du livre : ");
                scanf("%s", auteur[nombre]);

                printf("Entrez le prix du livre : ");
                scanf("%f", &prix[nombre]);

                printf("Entrez la quantite en stock : ");
                scanf("%d", &quantite[nombre]);

                nombre++;
                printf("Livre ajoute avec succès !\n");
                break;

            case 2:
                if (nombre == 0)
                {
                    printf("\nAucun livre n'a ete ajoute.\n");
                    break;
                }

                printf("\nVoici tous les livres disponibles :");
                for (int x = 0; x < nombre; x++)
                {
                    printf("\nLivre %d :\n", x + 1);
                    printf("Titre : %s\n", titre[x]);
                    printf("Auteur : %s\n", auteur[x]);
                    printf("Prix : %.2f\n", prix[x]);
                    printf("Quantite en stock : %d\n", quantite[x]);
                }
                break;

            case 3:
            {
                char nv[20];
                printf("Entrez le titre du livre dont vous voulez mettre a jour la quantite : ");
                scanf("%s", nv);

                int found = 0;
                for (int x = 0; x < nombre; x++)
                {
                    if (strcmp(nv, titre[x]) == 0)
                    {
                        printf("Entrez la nouvelle quantite : ");
                        scanf("%d", &new_quantity);

                        quantite[x] = new_quantity;
                        printf("Quantite mise a jour avec succès !\n");
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("Ce livre n'est pas disponible !\n");
                }
                break;
            }

            case 4:
            {
                char del[20];
                printf("Entrez le titre du livre a supprimer : ");
                scanf("%s", del);

                int found = 0;
                for (int x = 0; x < nombre; x++)
                {
                    if (strcmp(del, titre[x]) == 0)
                    {
                        for (int y = x; y < nombre - 1; y++)
                        {
                            strcpy(titre[y], titre[y + 1]);
                            strcpy(auteur[y], auteur[y + 1]);
                            prix[y] = prix[y + 1];
                            quantite[y] = quantite[y + 1];
                        }
                        nombre--;
                        printf("\nLivre supprime avec succes !\n");
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("Ce livre n'est pas disponible !\n");
                }
                break;
            }

            case 5:
            {
                int total = 0;
                for (int x = 0; x < nombre; x++)
                {
                    total += quantite[x];
                }
                printf("\nNombre total de livres en stock : %d\n", total);
                break;
            }

            case 6:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 6);

    return 0;
}

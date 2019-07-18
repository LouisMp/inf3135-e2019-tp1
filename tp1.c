#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_TAILLE 999
#define OUTSIDER 777
typedef struct Parameters Parameters;
struct Parameters
{
    bool c;
    char codePermanent[12];
    bool d;
    bool e;
    bool k;
    int cle;
    bool i;
    char inFichier [MAX_TAILLE];
    bool o;
    char outFichier [MAX_TAILLE];
    bool a;
    char cheminAlpha [MAX_TAILLE];
};
void cmdline (int argc, char *argv [], Parameters *param);
bool checkdigit (char chaine[]);
char crypter (char lettre, int key, const char alphabet[]);


int main(int argc, char *argv[])
{
    Parameters param = {false, "", false, false, false, 0, false, "", false, "", false, ""};
    cmdline (argc, argv, &param);
    printf("BIENVENUE ÉTUDIANT MATRUCULE %s :\n", param.codePermanent);
    char alphabet [27];
    char entree [MAX_TAILLE];
    FILE *in = NULL;
    FILE *out = NULL;
    FILE *abc = NULL;

    if(param.a)
    {
        abc = fopen(param.cheminAlpha, "r");
        if (abc != NULL)
        {
            fgets(alphabet, 27, abc);
            if (param.i)
            {
                in = fopen(param.inFichier, "r");
                if(in != NULL)
                {
                    while(fgets(entree,MAX_TAILLE, in) != NULL) {}
                    if (param.o)
                    {
                        out = fopen(param.outFichier,"w+");
                        if (out != NULL)
                        {
                            if (param.e)
                            {
                                for(int i = 0; i < (int)strlen(entree); i++)
                                {
                                    fputc(crypter(entree[i], param.cle, alphabet), out);
                                }

                                printf("\nRésultat de la requête enregistré dans le fichier %s.\nFin de programme normale.", param.outFichier);
                                fclose(abc);
                                fclose(in);
                                fclose(out);
                            }
                            else if (param.d)
                            {
                                for(int i = 0; i < (int)strlen(entree); i++)
                                {
                                    fputc(crypter(entree[i], param.cle*-1, alphabet), out);
                                }

                                printf("\nRésultat de la requête enregistré dans le fichier %s.\nFin de programme normale.", param.outFichier);
                                fclose(abc);
                                fclose(in);
                                fclose(out);
                            }
                        }
                        else
                        {
                            fclose(abc);
                            fclose(in);
                            fclose(out);
                            return 6;
                        }
                    }
                    else
                    {
                        out = fopen("sortie_standard.out","w+");
                        if (out != NULL)
                        {
                            if (param.e)
                            {
                                for(int i = 0; i < (int)strlen(entree); i++)
                                {
                                    fputc(crypter(entree[i], param.cle, alphabet), out);
                                }

                                printf("\nRésultat de la requête enregistré dans le fichier <sortie_standard.out>.\nFin de programme normale.");
                                fclose(abc);
                                fclose(in);
                                fclose(out);
                            }
                            else if (param.d)
                            {
                                for(int i = 0; i < (int)strlen(entree); i++)
                                {
                                    fputc(crypter(entree[i], param.cle*-1, alphabet), out);
                                }
                                printf("\nRésultat de la requête enregistré dans le fichier <sortie_standard.out>.\nFin de programme normale.");
                                fclose(abc);
                                fclose(in);
                                fclose(out);
                            }
                        }
                        else
                        {
                            fclose(abc);
                            fclose(in);
                            fclose(out);
                            return 6;
                        }
                    }

                }
                else
                {
                    fclose(abc);
                    fclose(in);
                    return 5;
                }

            }
            else
            {
                printf("\n Veuillez entrée la chaine à encrypter/décrypter : \n");
                fgets(entree, MAX_TAILLE, stdin);
                if (param.o)
                {
                    out = fopen(param.outFichier,"w+");
                    if (out != NULL)
                    {
                        if (param.e)
                        {
                            for(int i = 0; i < (int)strlen(entree); i++)
                            {
                                fputc(crypter(entree[i], param.cle, alphabet), out);
                            }
                            printf("\nRésultat de la requête enregistré dans le fichier %s.\nFin de programme normale.", param.outFichier);
                            fclose(abc);
                            fclose(out);
                        }
                        else if (param.d)
                        {
                            for(int i = 0; i < (int)strlen(entree); i++)
                            {
                                fputc(crypter(entree[i], param.cle*-1, alphabet), out);
                            }
                            printf("\nRésultat de la requête enregistré dans le fichier %s.\nFin de programme normale.", param.outFichier);
                            fclose(abc);
                            fclose(out);
                        }
                    }
                    else
                    {
                        fclose(abc);
                        fclose(out);
                        return 6;
                    }
                }
                else
                {
                    out = fopen("sortie_standard.out","w+");
                    if (out != NULL)
                    {
                        if (param.e)
                        {
                            for(int i = 0; i < (int)strlen(entree); i++)
                            {
                                fputc(crypter(entree[i], param.cle, alphabet), out);
                            }
                            printf("\nRésultat de la requête enregistré dans le fichier <sortie_standard.out>.\nFin de programme normale.");
                            fclose(abc);
                            fclose(out);
                        }
                        else if (param.d)
                        {
                            for(int i = 0; i < (int)strlen(entree); i++)
                            {

                                fputc(crypter(entree[i], param.cle*-1, alphabet), out);
                            }
                            printf("\nRésultat de la requête enregistré dans le fichier <sortie_standard.out>.\nFin de programme normale.");
                            fclose(abc);
                            fclose(out);
                        }
                    }
                    else
                    {
                        fclose(abc);
                        fclose(out);
                        return 6;
                    }
                }

            }

        }
        else
        {
            fclose(abc);
            return 8;
        }

    }
    else
    {
        abc = fopen("alphabet.txt", "r");
        if (abc != NULL)
        {
            fgets(alphabet, 27, abc);
            if (param.i)
            {
                in = fopen(param.inFichier, "r");
                if(in != NULL)
                {
                    while(fgets(entree,MAX_TAILLE, in) != NULL) {}
                    if (param.o)
                    {
                        out = fopen(param.outFichier,"w+");
                        if (out != NULL)
                        {
                            if (param.e)
                            {
                                for(int i = 0; i < (int)strlen(entree); i++)
                                {
                                    fputc(crypter(entree[i], param.cle, alphabet), out);
                                }
                                printf("\nRésultat de la requête enregistré dans le fichier %s.\nFin de programme normale.", param.outFichier);
                                fclose(abc);
                                fclose(in);
                                fclose(out);
                            }
                            else if (param.d)
                            {
                                for(int i = 0; i < (int)strlen(entree); i++)
                                {
                                    fputc(crypter(entree[i], param.cle*-1, alphabet), out);
                                }
                                printf("\nRésultat de la requête enregistré dans le fichier %s.\nFin de programme normale.", param.outFichier);
                                fclose(abc);
                                fclose(in);
                                fclose(out);
                            }
                        }
                        else
                        {
                            fclose(abc);
                            fclose(in);
                            fclose(out);
                            return 6;
                        }
                    }
                    else
                    {
                        out = fopen("sortie_standard.out","w+");
                        if (out != NULL)
                        {
                            if (param.e)
                            {
                                for(int i = 0; i < (int)strlen(entree); i++)
                                {
                                    fputc(crypter(entree[i], param.cle, alphabet), out);
                                }
                                printf("\nRésultat de la requête enregistré dans le fichier <sortie_standard.out>.\nFin de programme normale.");
                                fclose(abc);
                                fclose(in);
                                fclose(out);
                            }
                            else if (param.d)
                            {
                                for(int i = 0; i < (int)strlen(entree); i++)
                                {
                                    fputc(crypter(entree[i], param.cle*-1, alphabet), out);
                                }
                                printf("\nRésultat de la requête enregistré dans le fichier <sortie_standard.out>.\nFin de programme normale.");
                                fclose(abc);
                                fclose(in);
                                fclose(out);
                            }
                        }
                        else
                        {
                            fclose(abc);
                            fclose(in);
                            fclose(out);
                            return 6;
                        }
                    }

                }
                else
                {
                    fclose(abc);
                    fclose(in);
                    return 5;
                }

            }
            else
            {
                printf("\n Veuillez entrée la chaine à encrypter/décrypter : \n");
                fgets(entree, MAX_TAILLE, stdin);
                if (param.o)
                {
                    out = fopen(param.outFichier,"w+");
                    if (out != NULL)
                    {
                        if (param.e)
                        {
                            for(int i = 0; i < (int)strlen(entree); i++)
                            {
                                fputc(crypter(entree[i], param.cle, alphabet), out);
                            }
                            printf("\nRésultat de la requête enregistré dans le fichier %s.\nFin de programme normale.", param.outFichier);
                            fclose(abc);
                            fclose(out);
                        }
                        else if (param.d)
                        {
                            for(int i = 0; i < (int)strlen(entree); i++)
                            {
                                fputc(crypter(entree[i], param.cle*-1, alphabet), out);
                            }
                            printf("\nRésultat de la requête enregistré dans le fichier %s.\nFin de programme normale.", param.outFichier);
                            fclose(abc);
                            fclose(out);
                        }
                    }
                    else
                    {
                        fclose(abc);
                        fclose(out);
                        return 6;
                    }
                }
                else
                {
                    out = fopen("sortie_standard.out","w+");
                    if (out != NULL)
                    {
                        if (param.e)
                        {
                            for(int i = 0; i < (int)strlen(entree); i++)
                            {
                                fputc(crypter(entree[i], param.cle, alphabet), out);
                            }
                            printf("\nRésultat de la requête enregistré dans le fichier <sortie_standard.out>.\nFin de programme normale.");
                            fclose(abc);
                            fclose(out);
                        }
                        else if (param.d)
                        {
                            for(int i = 0; i < (int)strlen(entree); i++)
                            {
                                fputc(crypter(entree[i], param.cle*-1, alphabet), out);
                            }
                            printf("\nRésultat de la requête enregistré dans le fichier <sortie_standard.out>.\nFin de programme normale.");
                            fclose(abc);
                            fclose(out);
                        }
                    }
                    else
                    {
                        fclose(abc);
                        fclose(out);
                        return 6;
                    }
                }

            }

        }
        else
        {
            fclose(abc);
            return 8;
        }
    }
    return 0;
}


void cmdline (int argc, char *argv [], Parameters *param)
{
    int taille;
    FILE *fichier = NULL;

    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s <-c CODEpermanent> <-d | -e> <-k valeur> [-i fichier.in] [-o fichier.out] [-a chemin]\n", argv[0]);
        exit(1);
    }
    else
    {

        for(taille = 1; taille < argc; taille ++)
        {
            if (argv[taille][0] == '-' && argv[taille][1] == 'c')
            {
                param->c = true;
                if (strlen(argv[taille+1]) != 12 || argv[taille+1][0] == '-')
                {

                    printf("\nexit 2");
                    exit(2);
                }
                else
                {
                    strcpy(param->codePermanent, argv[taille+1]);
                }
                taille++;

            }
            else if (argv[taille][0] == '-' && (argv[taille][1] == 'd' || argv[taille][1] == 'e'))
            {
                if (argv[taille][1] == 'd')
                    param->d = true;
                else
                    param->e = true;
            }
            else if (argv[taille][0] == '-' && argv[taille][1] == 'k')
            {
                param->k = true;
                if (checkdigit(argv[taille+1]) == false)
                {
                    printf("exit 7");
                    exit (7);
                }
                else if (argv[taille+1][0] == '-')
                {
                    param->cle = atoi(argv[taille+1]) * -1;
                }
                else
                {
                    param->cle = atoi(argv[taille+1]);
                }
                taille ++;
            }
            else if (argv[taille][0] == '-' && argv[taille][1] == 'i')
            {
                param->i = true;
                fichier = fopen(argv[taille+1], "r");
                if (fichier == NULL)
                {
                    printf("exit 5");
                    fclose(fichier);
                    exit(5);
                }
                fclose(fichier);
                strcpy(param->inFichier, argv[taille+1]);
                taille++;
            }
            else if (argv[taille][0] == '-' && argv[taille][1] == 'o')
            {
                param->o = true;
                fichier = fopen(argv[taille+1], "w+");
                if (fichier == NULL)
                {
                    printf("exit 6");
                    fclose(fichier);
                    exit(6);
                }
                fclose(fichier);
                strcpy(param->outFichier, argv[taille+1]);
                taille ++;
            }
            else if (argv[taille][0] == '-' && argv[taille][1] == 'a')
            {
                param->a = true;
                fichier = fopen(argv[taille+1], "r");
                if (fichier == NULL)
                {
                    printf("exit 8");
                    fclose(fichier);
                    exit(8);
                }
                fclose(fichier);
                strcpy(param->cheminAlpha, argv[taille+1]);
                taille++;
            }
            else
            {
                printf("exit 3");
                exit(3); //fin du if else if
            }

        }//fin du for

        if (param->c == false)
        {
            fprintf(stderr, "Usage: %s <-c CODEpermanent> <-d | -e> <-k valeur> [-i fichier.in] [-o fichier.out] [-a chemin]\n", argv[0]);
            exit(1);
        }
        if (param->d == false && param->e == false)
        {
            exit(4);
        }
        if(param->k == false){
            exit(7);
        }
    }
}//fin de cmdline
bool checkdigit (char chaine[])
{
    int o;
    char liste [] = "+-0123456789";
    bool verif = true;
    for (o=0; chaine[o]!= '\0'; o++)
    {
        if(o>1 && (chaine[o] == '-' || chaine [o] == '+'))
        {
            verif = false;
        }
        else if (strchr(liste, (int)chaine[o])== NULL)
        {
            verif = false;
        }
    }// fin du for
    return verif;
}

char crypter (char lettre, int key, const char alphabet[])
{
    char crypt = lettre;
    int k;
    int position = OUTSIDER;
    for(k = 0; k<(int)strlen(alphabet); k++)
    {
        if (alphabet[k] == lettre)
            position = k;
    }
    if (position != OUTSIDER)
    {
        position+=key;
        if(position>25)
        {
            position-=26;
        }
        else if(position < 0)
        {
            position+=26;
        }

        crypt = alphabet[position];
    }


    return crypt;
}


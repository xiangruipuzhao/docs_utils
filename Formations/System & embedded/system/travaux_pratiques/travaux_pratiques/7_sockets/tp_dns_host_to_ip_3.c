/*
 * Recherche toutes les adresses IP d'un host avec getaddrinfo()
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
	struct addrinfo hints, *res, *p;
	int status;
	char ipstr[INET6_ADDRSTRLEN];

	if (argc != 2) {
		fprintf(stderr, "Usage: %s hostname\n", argv[0]);
		return 1;
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;		// AF_INET or AF_INET6 to force version
	hints.ai_socktype = SOCK_STREAM;

	if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return 1;
	}

	printf("IP addresses for %s:\n", argv[1]);

	for (p = res; p != NULL; p = p->ai_next) {
		void *addr;
		char *ipver;		// "IPv4" ou "IPv6"

		/*
		 * A completer : afficher toutes les adresses IP du host, en distinguant
		 * les adresses IPv4 et IPv6
		 *    - tester si l'adresse est IPv4 (p->ai_family)
		 *    - récupérer l'adresse dans une structure sockaddr_in ou sockaddr_in6
		 *    - faire pointer adrr sur l'adresse
		 *    - convertir l'adresse en chaine
		 */

		printf("  %s: %s\n", ipver, ipstr);
	}

	freeaddrinfo(res);

	return 0;
}

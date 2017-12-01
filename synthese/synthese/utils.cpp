#pragma once
#include <string>
#include <vector>

using namespace std;

void split(string str, string splitBy, vector<string>& tokens)
{
	/* Store the original string in the array, so we can loop the rest
	* of the algorithm. */
	tokens.push_back(str);

	// Store the split index in a 'size_t' (unsigned integer) type.
	size_t splitAt;
	// Store the size of what we're splicing out.
	size_t splitLen = splitBy.size();
	// Create a string for temporarily storing the fragment we're processing.
	std::string frag;
	// Loop infinitely - break is internal.
	while (true)
	{
		/* Store the last string in the vector, which is the only logical
		* candidate for processing. */
		frag = tokens.back();
		/* The index where the split is. */
		splitAt = frag.find(splitBy);
		// If we didn't find a new split point...
		if (splitAt == string::npos)
		{
			// Break the loop and (implicitly) return.
			break;
		}
		/* Put everything from the left side of the split where the string
		* being processed used to be. */
		tokens.back() = frag.substr(0, splitAt);
		/* Push everything from the right side of the split to the next empty
		* index in the vector. */
		tokens.push_back(frag.substr(splitAt + splitLen, frag.size() - (splitAt + splitLen)));
	}
}

void getComposants(string str, char splitDebut, char splitFin, vector<string>& composants) {

	int pos = 0, debut, fin;
	int hauteur = 0;

	while (pos < str.size()) {

		while (str[pos] != splitDebut && pos < str.size()) {
			pos++;//On cherche le caractère de début
		}
		debut = pos;
		pos++;
		hauteur++;

		while (hauteur != 0 && pos < str.size()) {
			if (str[pos] == splitFin) {
				hauteur--;
			}
			else {
				if (str[pos] == splitDebut) {
					hauteur++;
				}
			}
			pos++;
		}
		//pos >= longueur de la chaine OU on a trouvé la fin du composant
		if (pos <= str.size()) {
			fin = pos;
			composants.push_back(str.substr(debut + 1, fin - debut - 2));
		}		
	}
}
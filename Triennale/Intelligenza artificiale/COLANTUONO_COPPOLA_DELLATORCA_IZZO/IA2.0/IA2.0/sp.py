import spacy

nlp = spacy.load('en_core_web_sm')
tweets = open("tweets.txt", "r")
indice = 0
for contenuti in tweets.readlines():
	indice += 1
	doc = nlp(unicode(contenuti, "utf-8"))
	analizzato = open("anallizati.txt", 'a')
	
	analizzato.write("***********************************************ANALIZING TWEET NUMBER " + str(indice) + "...***************************************************************\n")
	analizzato.write("LEMMATIZZTION\n")
	analizzato.write("TEXT   LEMMA   POS   TAG   DEP\n")
	for token in doc:
		analizzato.write(token.text + '   ' +  token.lemma_ + '   ' + token.pos_ + '   ' + token.tag_ + '   ' + token.dep_ + '\n')

	analizzato.write("\nNOUN CHUNKS\n")
	analizzato.write("TEXT   ROOT_TEXT   ROOT_DEP   ROOT_HEAD_TEXT\n")
	for chunk in doc.noun_chunks:
		analizzato.write(chunk.text + '   ' + chunk.root.text + '   ' + chunk.root.dep_ + '   ' + chunk.root.head.text + '\n')

	analizzato.write("\nNAVIGATING THE PARSE TREE\n")
	analizzato.write("TEXT   DEP   HEAD_TEXT   HEAD_POS   CHILDREN\n")
	for token in doc:
		analizzato.write(token.text + '   ' + token.dep_ + '   ' + token.head.text + '   ' + token.head.pos_  + '   ' + str([child for child in token.children]) + '\n')

	analizzato.write("\nITERATING AROUND THE LOCAL TREE\n")
	analizzato.write("TEXT   DEP   N_LEFTS   N_RIGTHS   ANCESTORS\n")
	root = [token for token in doc if token.head == token][0]
	subject = list(root.lefts)[0]
	for descendant in subject.subtree:
		assert subject is descendant or subject.is_ancestor(descendant)
		analizzato.write(descendant.text + '   ' + descendant.dep_ + '   ' + str(descendant.n_lefts) + '   ' + str(descendant.n_rights) + '   ' + str([ancestor.text for ancestor in descendant.ancestors]) + '\n')

	analizzato.write("\nNAMED ENTITY RECOGNITION\n")
	analizzato.write("TEXT   START   END  LABEL   DESCRIPTION\n")
	for ent in doc.ents:
		analizzato.write(ent.text + '   ' + str(ent.start_char) + '   ' + str(ent.end_char) + '   ' + ent.label_)

	analizzato.write("\nSENTENCE RECOGNITION\n")
	for sent in doc.sents:
		analizzato.write(sent.text + '\n')
	
	analizzato.write('\n\n\n')
	print('DOCUMENTO ANALLIZZATO')

analizzato.close()
tweets.close()

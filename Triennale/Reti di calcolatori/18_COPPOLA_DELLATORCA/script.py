import subprocess
subprocess.run('touch traffic.gt.tie', shell=True)
print('Ho creato il file di destinazione')
subprocess.run('tshark -r traffic.pcap -T fields -e frame.time_epoch -e frame.protocols -e dns.a -e dns.qry.name -Y "(dns.flags.response == 1)" > outputdns.txt', shell=True)
print('Ho creato il file da cui poi prendo i dns')
subprocess.run('tshark -r traffic.pcap -T fields -e ssl.handshake.extensions_server_name  -e ip.src -e ip.dst -e tcp.srcport -e tcp.dstport > outputsni.txt', shell=True)
print('Ho creato il file da cui prenderò gli sni')
subprocess.run('touch outputwhois.txt', shell=True)
print('Ho creato un file utile per sni\n')

tie=open('traffic.tie')
ris=open('traffic.gt.tie', 'a')

for count in range(1,11):
	ris.write(tie.readline())

riga=tie.readline().split()
ris.write(riga[1] + '\t\t\t' + riga[2] + '\t\t\t' + riga[3] + '\t\t\t' + riga[4] + '\t\t\t' + riga[5] + '\t\t\t' + riga[6] + '\t\t\t' + riga[15] + '\t\t\t' + riga[16] + '\t\t\t' + 'validation' + '\t\t\t' + 'package' + '\t\t\t' + 'DNS' + '\t\t\t' + 'sni' + '\t\t\t' + 'whois' + '\n')

while 1:
	riga=tie.readline()
	if(riga=='# end of text table\n'):
		break
	else:
		parole=riga.split()
		if(parole[2]!='8.8.8.8'):

			#copio una quintupla con confidenza 0
			if(parole[15]=='0'):				
					ris.write(parole[0] + '\t\t' + parole[1] + '\t\t' + parole[2] + '\t\t' + parole[3] + '\t\t' + parole[4] + '\t\t' + parole[5] + '\t\t' + parole[14] + '\t\t' + parole[15] + '\t\t' + '\t\t' + 'non_classificato' + '\n')
					print('Ho copiato una quintupla non classificata')

			#copio una quintupla con confidenza 100
			if(parole[15]=='100'):
				classificazione='classificato'
				ris.write(parole[0] + '\t\t' + parole[1] + '\t\t' + parole[2] + '\t\t' + parole[3] + '\t\t' + parole[4] + '\t\t' + parole[5] + '\t\t' + parole[14] + '\t\t' + parole[15] + '\t\t' + classificazione + '\t\t')
				print('Ho copiato una riga classificata')

				#controllo il package in strace.log
				log=open('strace.log')
				while 1:
					riga_log=log.readline()
					if(riga_log==''):
						print('Non ho trovato il package')
						log.close()
						ris.write('UNKNOWN\t\t')
						break
					#copio il suo package
					if((riga_log.find(parole[1] + ':' + parole[4])>=0) and (riga_log.find(parole[2] + ':' + parole[5])>=0)):
						parole_log=riga_log.split()
						ris.write( parole_log[0] + '\t\t')
						print('Ho trovato il suo package')
						log.close()
						break

				#controllo il suo dns in outputdns.txt
				dns=open('outputdns.txt')
				while 1:
					riga_dns=dns.readline()
					if(riga_dns==''):
						print('Non fo trovato il dns')
						dns.close()
						ris.write('UNKNOWN\t\t')
						break
					#copio il suo dns
					if(riga_dns.find(parole[2])>=0):
						parole_dns=riga_dns.split()
						ris.write(parole_dns[3] + '\t\t')
						print('Ho trovato il suo DNS')
						dns.close()
						break	

				#controllo il suo sni in outputsni.txt
				sni=open('outputsni.txt')
				while 1:
					riga_sni=sni.readline()
					if(riga_sni==''):
						ris.write('UNKNOWN\t\t')
						sni.close()
						break
					#copio il suo sni
					if(parole[1] in riga_sni and parole[2] in riga_sni and parole[4] in riga_sni and parole[5] in riga_sni):
						parole_sni=riga_sni.split('\t')
						if(parole_sni[0] != ''):
							ris.write(parole_sni[0])
							print('Ho trovato il suo sni')
							sni.close()
							break
							sni.close()

				#controllo il suo whois in outputwhois.txt
				who=open('outputwhois.txt', 'w+')
				subprocess.run('whois ' + parole[2] + ' | awk /OrgName/' + ' | cut -f 2 -d:', stdout=who, shell=True)
				who.close()
				who=open('outputwhois.txt')
				rigawho=who.readline()
				if(rigawho==''):
					ris.write('\t\tUNKNOWN\n')
					print('Non ho trovato il whois')
					who.close()
				#copio il suo whois
				else:
					ris.write(rigawho)
					who.close()
					print('Ho trovato il whois')

		
tie.close()
ris.close()
print('Operazione terminata')

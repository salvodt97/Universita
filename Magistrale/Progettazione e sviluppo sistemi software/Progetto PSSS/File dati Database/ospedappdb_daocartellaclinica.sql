-- MySQL dump 10.13  Distrib 8.0.21, for Win64 (x86_64)
--
-- Host: localhost    Database: ospedappdb
-- ------------------------------------------------------
-- Server version	8.0.21

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `daocartellaclinica`
--

DROP TABLE IF EXISTS `daocartellaclinica`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `daocartellaclinica` (
  `IDCartella` int NOT NULL AUTO_INCREMENT,
  `stato` tinyint DEFAULT NULL,
  `motivo_ricovero` varchar(255) DEFAULT NULL,
  `anamnesi` varchar(255) DEFAULT NULL,
  `data_ricovero` varchar(45) DEFAULT NULL,
  `Utente_creazione` varchar(45) DEFAULT NULL,
  `Medico_aggiornamento` varchar(45) DEFAULT NULL,
  `Medico_visualizzazione` varchar(45) DEFAULT NULL,
  `Infermiere_visualizzazione` varchar(45) DEFAULT NULL,
  `Paziente_codice_fiscale` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`IDCartella`),
  KEY `fk_CartellaClinica_Utente_idx` (`Utente_creazione`),
  KEY `fk_DaoCartellaClinica_DaoUtente1_idx` (`Medico_aggiornamento`),
  KEY `fk_DaoCartellaClinica_DaoUtente2_idx` (`Medico_visualizzazione`),
  KEY `fk_DaoCartellaClinica_DaoUtente3_idx` (`Infermiere_visualizzazione`),
  KEY `fk_DaoCartellaClinica_DaoPaziente1_idx` (`Paziente_codice_fiscale`),
  CONSTRAINT `fk_CartellaClinica_Utente` FOREIGN KEY (`Utente_creazione`) REFERENCES `daoutente` (`username`),
  CONSTRAINT `fk_DaoCartellaClinica_DaoPaziente1` FOREIGN KEY (`Paziente_codice_fiscale`) REFERENCES `daopaziente` (`codice_fiscale`),
  CONSTRAINT `fk_DaoCartellaClinica_DaoUtente1` FOREIGN KEY (`Medico_aggiornamento`) REFERENCES `daoutente` (`username`),
  CONSTRAINT `fk_DaoCartellaClinica_DaoUtente2` FOREIGN KEY (`Medico_visualizzazione`) REFERENCES `daoutente` (`username`),
  CONSTRAINT `fk_DaoCartellaClinica_DaoUtente3` FOREIGN KEY (`Infermiere_visualizzazione`) REFERENCES `daoutente` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `daocartellaclinica`
--

LOCK TABLES `daocartellaclinica` WRITE;
/*!40000 ALTER TABLE `daocartellaclinica` DISABLE KEYS */;
INSERT INTO `daocartellaclinica` VALUES (10,1,'dolore addominale','il paziente presentava sintomi di dolore addominale da alcuni giorni','2020/09/22 17:07:48','medico',NULL,NULL,NULL,'GNNSPS01P19F839G');
/*!40000 ALTER TABLE `daocartellaclinica` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-09-22 17:11:19

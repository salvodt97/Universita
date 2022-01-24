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
-- Table structure for table `daorichiestaesame`
--

DROP TABLE IF EXISTS `daorichiestaesame`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `daorichiestaesame` (
  `IDRichiesta` int NOT NULL,
  `data_esame` varchar(45) DEFAULT NULL,
  `ora_esame` varchar(45) DEFAULT NULL,
  `Utente_username` varchar(45) DEFAULT NULL,
  `Esame_codice` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`IDRichiesta`),
  KEY `fk_RichiestaEsame_Utente1_idx` (`Utente_username`),
  KEY `fk_RichiestaEsame_Esame1_idx` (`Esame_codice`),
  CONSTRAINT `fk_RichiestaEsame_Esame1` FOREIGN KEY (`Esame_codice`) REFERENCES `daoesame` (`codice`),
  CONSTRAINT `fk_RichiestaEsame_Utente1` FOREIGN KEY (`Utente_username`) REFERENCES `daoutente` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `daorichiestaesame`
--

LOCK TABLES `daorichiestaesame` WRITE;
/*!40000 ALTER TABLE `daorichiestaesame` DISABLE KEYS */;
/*!40000 ALTER TABLE `daorichiestaesame` ENABLE KEYS */;
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

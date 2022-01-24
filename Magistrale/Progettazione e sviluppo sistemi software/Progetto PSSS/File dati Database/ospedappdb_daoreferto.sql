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
-- Table structure for table `daoreferto`
--

DROP TABLE IF EXISTS `daoreferto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `daoreferto` (
  `IDReferto` int NOT NULL,
  `note` varchar(255) NOT NULL,
  `esito` varchar(255) NOT NULL,
  `CartellaClinica_IDCartella` int DEFAULT NULL,
  `Esame_codice` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`IDReferto`),
  KEY `fk_Referto_CartellaClinica1_idx` (`CartellaClinica_IDCartella`),
  KEY `fk_Referto_Esame1_idx` (`Esame_codice`),
  CONSTRAINT `fk_Referto_CartellaClinica1` FOREIGN KEY (`CartellaClinica_IDCartella`) REFERENCES `daocartellaclinica` (`IDCartella`),
  CONSTRAINT `fk_Referto_Esame1` FOREIGN KEY (`Esame_codice`) REFERENCES `daoesame` (`codice`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `daoreferto`
--

LOCK TABLES `daoreferto` WRITE;
/*!40000 ALTER TABLE `daoreferto` DISABLE KEYS */;
/*!40000 ALTER TABLE `daoreferto` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-09-22 17:11:18

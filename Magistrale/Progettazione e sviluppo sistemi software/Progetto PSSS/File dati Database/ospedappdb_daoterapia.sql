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
-- Table structure for table `daoterapia`
--

DROP TABLE IF EXISTS `daoterapia`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `daoterapia` (
  `IDTerapia` int NOT NULL AUTO_INCREMENT,
  `principio_attivo` varchar(255) DEFAULT NULL,
  `data_fine` varchar(45) DEFAULT NULL,
  `data_inizio` varchar(45) DEFAULT NULL,
  `posologia` varchar(45) DEFAULT NULL,
  `dosaggio` varchar(255) DEFAULT NULL,
  `IDCartellaClinica` int DEFAULT NULL,
  PRIMARY KEY (`IDTerapia`),
  KEY `fk_Terapia_CartellaClinica1_idx` (`IDCartellaClinica`),
  CONSTRAINT `fk_Terapia_CartellaClinica1` FOREIGN KEY (`IDCartellaClinica`) REFERENCES `daocartellaclinica` (`IDCartella`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `daoterapia`
--

LOCK TABLES `daoterapia` WRITE;
/*!40000 ALTER TABLE `daoterapia` DISABLE KEYS */;
INSERT INTO `daoterapia` VALUES (8,'omeoprazolo','','2020/09/22 17:07:48','3 volte al giorno','15mg',10);
/*!40000 ALTER TABLE `daoterapia` ENABLE KEYS */;
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

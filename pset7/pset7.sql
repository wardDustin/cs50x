-- MySQL dump 10.13  Distrib 5.5.46, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.46-0ubuntu0.14.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `userID` varchar(255) NOT NULL,
  `time` datetime NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  `action` char(4) NOT NULL,
  `price` decimal(65,4) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=47 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (8,'9','2016-04-12 23:26:25','PEP',10,'BUY',104.9100),(9,'9','2016-04-12 23:27:14','PEP',5,'SELL',104.9100),(10,'15','2016-04-12 23:43:37','PEP',10,'BUY',104.9100),(11,'15','2016-04-12 23:50:21','FREE',1000,'BUY',0.0100),(12,'15','2016-04-12 23:51:26','FREE',500,'SELL',0.0100),(13,'15','2016-04-12 23:51:41','FREE',500,'SELL',0.0100),(14,'15','2016-04-12 23:51:49','PEP',10,'SELL',104.9100),(15,'15','2016-04-12 23:53:44','FREE',1000,'BUY',0.0100),(16,'15','2016-04-12 23:53:51','PEP',20,'BUY',104.9100),(17,'15','2016-04-12 23:54:00','FREE',500,'SELL',0.0100),(18,'15','2016-04-12 23:54:06','FREE',500,'SELL',0.0100),(19,'15','2016-04-12 23:54:13','PEP',20,'SELL',104.9100),(20,'15','2016-04-12 23:54:28','FREE',1000,'BUY',0.0100),(21,'15','2016-04-12 23:54:38','FREE',500,'SELL',0.0100),(22,'15','2016-04-12 23:54:48','FREE',500,'SELL',0.0100),(23,'15','2016-04-12 23:54:55','PEP',20,'BUY',104.9100),(24,'15','2016-04-12 23:55:02','PEP',20,'SELL',104.9100),(25,'15','2016-04-12 23:56:42','FREE',10000,'BUY',0.0100),(26,'15','2016-04-12 23:56:59','FREE',10000,'SELL',0.0100),(27,'15','2016-04-12 23:57:12','PEP',20,'BUY',104.9100),(28,'15','2016-04-12 23:58:29','PEP',20,'SELL',104.9100),(29,'15','2016-04-13 00:01:30','PEP',20,'BUY',104.9100),(30,'15','2016-04-13 00:01:49','PEP',20,'SELL',104.9100),(31,'15','2016-04-13 00:03:25','PEP',20,'BUY',104.9100),(32,'15','2016-04-13 00:03:38','PEP',20,'SELL',104.9100),(33,'15','2016-04-13 00:16:03','PEP',20,'BUY',104.9100),(34,'15','2016-04-13 00:16:11','PEP',20,'SELL',104.9100),(35,'15','2016-04-13 00:22:17','PEP',20,'BUY',104.9100),(36,'15','2016-04-13 00:22:24','PEP',20,'SELL',104.9100),(37,'15','2016-04-13 00:22:46','PEP',20,'BUY',104.9100),(38,'15','2016-04-13 00:22:54','PEP',20,'SELL',104.9100),(39,'15','2016-04-13 00:47:26','PEP',20,'BUY',104.9100),(40,'15','2016-04-13 00:47:38','PEP',20,'SELL',104.9100),(41,'15','2016-04-13 00:49:29','PEP',20,'BUY',104.9100),(42,'15','2016-04-13 00:49:39','PEP',20,'SELL',104.9100),(43,'15','2016-04-13 00:49:56','PEP',20,'BUY',104.9100),(44,'15','2016-04-13 00:50:19','PEP',10,'SELL',104.9100),(45,'15','2016-04-13 00:51:02','PEP',10,'SELL',104.9100),(46,'15','2016-04-13 03:34:13','FREE',234,'BUY',0.0100);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`),
  UNIQUE KEY `user_id_2` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=38 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
INSERT INTO `portfolio` VALUES (3,9,'goog',100),(4,9,'amzn',15),(12,9,'PEP',15),(19,17,'ALL',5),(37,15,'FREE',234);
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',10000.0000),(2,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',10000.0000),(3,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',10000.0000),(4,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',10000.0000),(5,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',10000.0000),(6,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',10000.0000),(7,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',10000.0000),(8,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',10000.0000),(9,'skroob','$2y$10$9hgfK6szUQmu5Ugt5rOGau6HCrTBk1cVoW2nQct7Ej2rG3lkQHwCO',5327.7605),(10,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',10000.0000),(15,'dusty','$2y$10$nPScnGX6KC1S7tgGO3keWOALR15izSHUyIp7twkjASeRzuyoM3BQC',10000.0000),(17,'Crispy','$2y$10$C.SyfYYII0N9oryulz4Vj.exgMl4v6JRVUYh0k62jPu3JLmuY56Xq',9663.9500);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-04-13 14:58:56

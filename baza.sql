-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               5.5.28a-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win32
-- HeidiSQL version:             7.0.0.4053
-- Date/time:                    2013-01-08 12:39:24
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- Dumping database structure for serwer
DROP DATABASE IF EXISTS `serwer`;
CREATE DATABASE IF NOT EXISTS `serwer` /*!40100 DEFAULT CHARACTER SET utf8 COLLATE utf8_polish_ci */;
USE `serwer`;


-- Dumping structure for table serwer.uzytkownicy
DROP TABLE IF EXISTS `uzytkownicy`;
CREATE TABLE IF NOT EXISTS `uzytkownicy` (
  `login` int(10) unsigned NOT NULL,
  `mail` varchar(50) COLLATE utf8_polish_ci NOT NULL,
  `haslo` char(50) COLLATE utf8_polish_ci NOT NULL,
  PRIMARY KEY (`login`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

-- Dumping data for table serwer.uzytkownicy: ~0 rows (approximately)
DELETE FROM `uzytkownicy`;
/*!40000 ALTER TABLE `uzytkownicy` DISABLE KEYS */;
/*!40000 ALTER TABLE `uzytkownicy` ENABLE KEYS */;


-- Dumping structure for table serwer.wiadomosci
DROP TABLE IF EXISTS `wiadomosci`;
CREATE TABLE IF NOT EXISTS `wiadomosci` (
  `ID` int(10) NOT NULL,
  `idOdbiorcy` int(10) unsigned NOT NULL,
  `Tresc` text COLLATE utf8_polish_ci NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `FK_wiadomosci_uzytkownicy` (`idOdbiorcy`),
  CONSTRAINT `FK_wiadomosci_uzytkownicy` FOREIGN KEY (`idOdbiorcy`) REFERENCES `uzytkownicy` (`login`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

-- Dumping data for table serwer.wiadomosci: ~0 rows (approximately)
DELETE FROM `wiadomosci`;
/*!40000 ALTER TABLE `wiadomosci` DISABLE KEYS */;
/*!40000 ALTER TABLE `wiadomosci` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;

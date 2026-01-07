-- Create Database
CREATE DATABASE IF NOT EXISTS praktikum_20230140145_db;
USE praktikum_20230140145_db;

-- Create Table Presensis
CREATE TABLE IF NOT EXISTS `Presensis` (
  `id` INTEGER NOT NULL auto_increment,
  `userId` INTEGER NOT NULL,
  `nama` VARCHAR(255) NOT NULL,
  `checkIn` DATETIME NOT NULL,
  `checkOut` DATETIME,
  `createdAt` DATETIME NOT NULL,
  `updatedAt` DATETIME NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB;

drop database praktikum_nim_db
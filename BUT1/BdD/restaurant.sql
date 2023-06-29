-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  mar. 22 nov. 2022 à 12:58
-- Version du serveur :  8.0.18
-- Version de PHP :  7.2.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `restaurant`
--

-- --------------------------------------------------------

--
-- Structure de la table `achat`
--

DROP TABLE IF EXISTS `achat`;
CREATE TABLE IF NOT EXISTS `achat` (
  `num_ticket` varchar(5) NOT NULL,
  `num_prest` int(11) NOT NULL,
  `nb_prest` int(11) NOT NULL,
  PRIMARY KEY (`num_ticket`,`num_prest`),
  KEY `num_prest` (`num_prest`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `achat`
--

INSERT INTO `achat` (`num_ticket`, `num_prest`, `nb_prest`) VALUES
('TI1', 1, 1),
('TI10', 1, 1),
('TI10', 4, 3),
('TI11', 1, 1),
('TI11', 4, 1),
('TI12', 1, 1),
('TI12', 4, 3),
('TI12', 5, 2),
('TI13', 1, 1),
('TI13', 2, 2),
('TI14', 2, 1),
('TI2', 1, 1),
('TI2', 4, 1),
('TI3', 1, 1),
('TI3', 5, 2),
('TI4', 1, 1),
('TI4', 4, 1),
('TI5', 2, 1),
('TI6', 1, 1),
('TI7', 1, 1),
('TI8', 1, 1),
('TI9', 5, 3);

-- --------------------------------------------------------

--
-- Structure de la table `categorie`
--

DROP TABLE IF EXISTS `categorie`;
CREATE TABLE IF NOT EXISTS `categorie` (
  `num_categ` varchar(5) NOT NULL,
  `lib_categ` varchar(100) NOT NULL,
  PRIMARY KEY (`num_categ`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `categorie`
--

INSERT INTO `categorie` (`num_categ`, `lib_categ`) VALUES
('T1', 'petits revenus'),
('T2', 'gros revenus');

-- --------------------------------------------------------

--
-- Structure de la table `depot`
--

DROP TABLE IF EXISTS `depot`;
CREATE TABLE IF NOT EXISTS `depot` (
  `num_carte` varchar(5) NOT NULL,
  `date_depot` date NOT NULL,
  `montant` int(11) NOT NULL,
  PRIMARY KEY (`num_carte`,`date_depot`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `depot`
--

INSERT INTO `depot` (`num_carte`, `date_depot`, `montant`) VALUES
('C1', '2018-04-22', 10),
('C1', '2018-05-24', 10),
('C1', '2019-10-01', 15),
('C1', '2020-03-03', 30),
('C2', '2018-05-24', 15),
('C2', '2019-10-01', 10),
('C3', '2019-06-22', 20),
('C4', '2019-10-01', 20),
('C5', '2020-02-02', 20),
('C5', '2020-03-02', 10),
('C5', '2020-05-02', 15),
('C6', '2021-04-01', 20);

-- --------------------------------------------------------

--
-- Structure de la table `prestation`
--

DROP TABLE IF EXISTS `prestation`;
CREATE TABLE IF NOT EXISTS `prestation` (
  `num_prest` int(11) NOT NULL,
  `type_prest` varchar(100) NOT NULL,
  PRIMARY KEY (`num_prest`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `prestation`
--

INSERT INTO `prestation` (`num_prest`, `type_prest`) VALUES
(1, 'repas normal'),
(2, 'quart de vin rouge'),
(3, 'bière'),
(4, 'supplément frites'),
(5, 'supplément chantilly');

-- --------------------------------------------------------

--
-- Structure de la table `tarif`
--

DROP TABLE IF EXISTS `tarif`;
CREATE TABLE IF NOT EXISTS `tarif` (
  `num_prest` int(11) NOT NULL,
  `num_categ` varchar(5) NOT NULL,
  `prix` float NOT NULL,
  PRIMARY KEY (`num_prest`,`num_categ`),
  KEY `num_categ` (`num_categ`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `tarif`
--

INSERT INTO `tarif` (`num_prest`, `num_categ`, `prix`) VALUES
(1, 'T1', 4),
(1, 'T2', 5),
(2, 'T1', 1),
(2, 'T2', 1),
(3, 'T1', 1),
(3, 'T2', 1),
(4, 'T1', 0.5),
(4, 'T2', 0.6),
(5, 'T1', 0.5),
(5, 'T2', 0.6);

-- --------------------------------------------------------

--
-- Structure de la table `ticket`
--

DROP TABLE IF EXISTS `ticket`;
CREATE TABLE IF NOT EXISTS `ticket` (
  `num_ticket` varchar(5) NOT NULL,
  `num_carte` varchar(5) NOT NULL,
  `date_achat` date NOT NULL,
  PRIMARY KEY (`num_ticket`),
  KEY `num_carte` (`num_carte`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `ticket`
--

INSERT INTO `ticket` (`num_ticket`, `num_carte`, `date_achat`) VALUES
('TI1', 'C1', '2018-04-22'),
('TI10', 'C5', '2020-02-02'),
('TI11', 'C1', '2020-03-02'),
('TI12', 'C5', '2020-03-04'),
('TI13', 'C6', '2021-04-01'),
('TI14', 'C6', '2021-04-01'),
('TI2', 'C1', '2018-04-24'),
('TI3', 'C2', '2018-05-24'),
('TI4', 'C1', '2018-05-26'),
('TI5', 'C1', '2018-05-26'),
('TI6', 'C3', '2019-06-22'),
('TI7', 'C4', '2019-10-02'),
('TI8', 'C2', '2019-10-02'),
('TI9', 'C2', '2019-10-02');

-- --------------------------------------------------------

--
-- Structure de la table `usager`
--

DROP TABLE IF EXISTS `usager`;
CREATE TABLE IF NOT EXISTS `usager` (
  `num_carte` varchar(5) NOT NULL,
  `nom` varchar(100) NOT NULL,
  `num_categ` varchar(5) NOT NULL,
  `mt_caution` int(11) NOT NULL,
  `date_carte` date NOT NULL,
  PRIMARY KEY (`num_carte`),
  KEY `num_categ` (`num_categ`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `usager`
--

INSERT INTO `usager` (`num_carte`, `nom`, `num_categ`, `mt_caution`, `date_carte`) VALUES
('C1', 'Pierre L.', 'T2', 5, '2017-04-19'),
('C2', 'Zsuzanna R.', 'T1', 5, '2017-05-20'),
('C3', 'Michel A.', 'T2', 6, '2018-06-22'),
('C4', 'Nathalie B.', 'T1', 6, '2018-09-30'),
('C5', 'Franc M.', 'T2', 6, '2019-01-31'),
('C6', 'Bernard H.', 'T2', 7, '2020-04-01');

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `achat`
--
ALTER TABLE `achat`
  ADD CONSTRAINT `achat_ibfk_1` FOREIGN KEY (`num_ticket`) REFERENCES `ticket` (`num_ticket`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `achat_ibfk_2` FOREIGN KEY (`num_prest`) REFERENCES `prestation` (`num_prest`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `depot`
--
ALTER TABLE `depot`
  ADD CONSTRAINT `depot_ibfk_1` FOREIGN KEY (`num_carte`) REFERENCES `usager` (`num_carte`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `tarif`
--
ALTER TABLE `tarif`
  ADD CONSTRAINT `tarif_ibfk_1` FOREIGN KEY (`num_categ`) REFERENCES `categorie` (`num_categ`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `tarif_ibfk_2` FOREIGN KEY (`num_prest`) REFERENCES `prestation` (`num_prest`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `ticket`
--
ALTER TABLE `ticket`
  ADD CONSTRAINT `ticket_ibfk_1` FOREIGN KEY (`num_carte`) REFERENCES `usager` (`num_carte`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `usager`
--
ALTER TABLE `usager`
  ADD CONSTRAINT `usager_ibfk_1` FOREIGN KEY (`num_categ`) REFERENCES `categorie` (`num_categ`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

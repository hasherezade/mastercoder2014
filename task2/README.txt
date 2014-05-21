Mastercoder Zadanie 2 : W poszukiwaniu zaginionego wzorca
Autor rozwiązania: hasherezade@op.pl
Użyty wzorzec bazowy: Fabryka
Notatka:
	Wzorzec "Fabryka" został zmodyfikowany, tak, żeby wspierane typy mogły być dodawane z zewnątrz, np.

	installersFactory.supportOS(LINUX, new LinuxCliInstallerBuilder());

	serviceInstaller.supportComponentType(Component::CLI, new CliInstallersFactory());
